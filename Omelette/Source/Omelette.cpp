#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h> // Keyboard mapping from DirectInput

#include "Omelette.h"
#include "GUI.h"
#include "Settings.h"
#include "Memory.h"
#include "Features/Features.h"


DWORD WINAPI GUIThread(LPVOID param)
{
    Settings* settings = (Settings*)param;

    // Create GUI
    GUI::CreateHWindow(L"Omelette");
    GUI::CreateDevice();
    GUI::CreateImGui();

    while (settings->showMenu)
    {
        GUI::BeginRender(settings);
        GUI::Render(settings);
        GUI::EndRender();

        Sleep(10);
    }

    // Destroy GUI
    GUI::DestroyImGui();
    GUI::DestroyDevice();
    GUI::DestroyHWindow();

    return 0;
}

void cheat::start(HMODULE instance)
{
    HANDLE GUIThreadHandle{};
    Features features = Features();
    Settings settings;

    while (true)
    {
        if (GetAsyncKeyState(VK_INSERT) & 0x01)
        {
            settings.showMenu = !settings.showMenu;
        }

        if (GetAsyncKeyState(VK_END) & 0x01)
        {
            settings.showMenu = false;

            FreeLibraryAndExitThread(instance, 0);
            // TODO: remove ImGui if it not closed or the game crashes
        }

        if (settings.showMenu && !GUIThreadHandle)
        {
            GUIThreadHandle = CreateThread(NULL, 0, &GUIThread, &settings, 0, 0);
        }
        else if (!settings.showMenu && GUIThreadHandle)
        {
            CloseHandle(GUIThread);
            GUIThreadHandle = {};
        }

        Context::playerData = (PlayerData*)memory::getAddress(settings.playerId);

        features.autoshoot.run(&settings);
        features.debugmode.run(&settings);
        features.firepower.run(&settings);
        features.ingamecheats.run(&settings);
        features.shield.run(&settings);

        Sleep(10);
    }
}
