#define DIRECTINPUT_VERSION 0x0700
#include <dinput.h>
#include <iostream>
#include "MinHook.h"

#include "Omelette.h"
#include "GUI.h"
#include "Memory.h"
#include "Features/Features.h"
#include "Settings.h"

FeaturesManager& featuresManager = FeaturesManager::getInstance();
Settings& settings = Settings::getInstance();

typedef void*(__cdecl* _dynamicMemoryAllocation)(size_t size);
_dynamicMemoryAllocation dynamicMemoryAllocation;

typedef DWORD* (__cdecl* _sub_401F18)(DWORD* a1, int a2, int a3, int a4);
_sub_401F18 sub_401F18;

typedef void* (__cdecl* _sub_40D780)(DWORD* a1, int a2);
_sub_40D780 sub_40D780;

typedef HRESULT(WINAPI* GetDeviceStateT)(
    LPDIRECTINPUTDEVICEA _this,
    DWORD cbData,
    LPVOID lpvData
);
GetDeviceStateT GetDeviceStateOriginal = nullptr;
GetDeviceStateT GetDeviceStateTarget;

DWORD WINAPI GUIThread(LPVOID param)
{
    // Create GUI
    GUI::CreateHWindow(L"Omelette");
    GUI::CreateDevice();
    GUI::CreateImGui();

    while (settings.showMenu)
    {
        GUI::BeginRender(&settings);
        GUI::Render(&settings);
        GUI::EndRender();

        Sleep(10);
    }

    // Destroy GUI
    GUI::DestroyImGui();
    GUI::DestroyDevice();
    GUI::DestroyHWindow();

    return EXIT_SUCCESS;
}

HRESULT WINAPI hookGetDeviceState(LPDIRECTINPUTDEVICEA _this, DWORD cbData, LPVOID lpvData) {
    HRESULT result = GetDeviceStateOriginal(_this, cbData, lpvData);

    if (result == DI_OK) {
        featuresManager.autoshoot.run(cbData, lpvData);
    }

    return result;
}

void cheat::start(HMODULE instance) noexcept
{
    HANDLE GUIThreadHandle{};

    if (MH_Initialize() != MH_OK) {
        return;
    }

    LPDIRECTINPUTA directInput = nullptr;
    if (DirectInputCreateA(instance, DIRECTINPUT_VERSION, &directInput, NULL) != DI_OK) {
        return;
    }

    LPDIRECTINPUTDEVICEA keyboardDevice;
    if (directInput->CreateDevice(GUID_SysKeyboard, &keyboardDevice, NULL) != DI_OK) {
        directInput->Release();
        return;
    }

    uintptr_t vTable = *(uintptr_t*)keyboardDevice;
    uintptr_t GetDeviceStatePtr = vTable + 9 * sizeof(uintptr_t);
    GetDeviceStateTarget = (GetDeviceStateT)(*(uintptr_t*)GetDeviceStatePtr);

    if (MH_CreateHook((LPVOID*)GetDeviceStateTarget, &hookGetDeviceState, (LPVOID*)&GetDeviceStateOriginal) != MH_OK) {
        std::cout << "MinHook create failed" << std::endl;
        return;
    }

    
    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
        std::cout << "MinHook enable failed" << std::endl;
        return;
    }

    while (TRUE)
    {
        if (GetAsyncKeyState(VK_INSERT) & 0x01)
        {
            settings.showMenu = !settings.showMenu;
        }

        if (GetAsyncKeyState(VK_END) & 0x01)
        {
            settings.showMenu = false;

            break;
        }
        
        if (settings.showMenu && !GUIThreadHandle)
        {
            GUIThreadHandle = CreateThread(NULL, 0, &GUIThread, NULL, 0, 0);
        }
        else if (!settings.showMenu && GUIThreadHandle)
        {
            CloseHandle(GUIThread);
            GUIThreadHandle = {};
        }
        
        Context::playerData = (PlayerData*)memory::getAddress(settings.playerId);
        
        if (GetAsyncKeyState(VK_NUMPAD1) & 0x01)
        {
            // gift spawning

            PVOID allocatedPtr = nullptr;
            dynamicMemoryAllocation = (_dynamicMemoryAllocation)(Context::moduleBase + 0x40B10);
            sub_401F18 = (_sub_401F18)(Context::moduleBase + 0x1F18);
            sub_40D780 = (_sub_40D780)(Context::moduleBase + 0xD780);

            allocatedPtr = dynamicMemoryAllocation(0xB0);

            if (allocatedPtr)
            {
                uintptr_t* chickenDwordC = (uintptr_t*)getPtrAddr(Context::moduleBase + Context::baseOffset, { 0x298, 0x40, 0x14, 0xC });

                sub_401F18((DWORD*)allocatedPtr, *chickenDwordC, 320, 240);
            }

            sub_40D780((DWORD*)getPtrAddr(Context::moduleBase + Context::baseOffset, { 0x298, 0x5C, 0x14 }), (uintptr_t)allocatedPtr);
        }

        featuresManager.debugmode.run();
        featuresManager.firepower.run();
        featuresManager.ingamecheats.run();
        featuresManager.shield.run();

        Sleep(10);
    }

    MH_DisableHook(MH_ALL_HOOKS);
    FreeLibraryAndExitThread(instance, 0);
    // TODO: remove ImGui if it is not closed or the game crashes
}
