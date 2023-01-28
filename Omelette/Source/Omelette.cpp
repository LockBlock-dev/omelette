#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h> // Keyboard mapping from DirectInput
#include <optional>

#include "Omelette.h"
#include "GUI.h"
#include "Settings.h"
#include "Memory.h"
#include "Features/Features.h"


DWORD WINAPI GUIThread(LPVOID param)
{
    // Create GUI
    gui::CreateHWindow(L"Omelette");
    gui::CreateDevice();
    gui::CreateImGui();

    while (settings::cheats.showMenu)
    {
        gui::BeginRender();
        gui::Render();
        gui::EndRender();

        Sleep(10);
    }

    // Destroy GUI
    gui::DestroyImGui();
    gui::DestroyDevice();
    gui::DestroyHWindow();

    return 0;
}

void cheat::start(HMODULE instance)
{
    HANDLE GUIThreadHandle{};
    std::optional<Features> features = Features();

    while (true)
    {
        if (GetAsyncKeyState(VK_INSERT) & 0x01)
        {
            settings::cheats.showMenu = !settings::cheats.showMenu;
        }

        if (GetAsyncKeyState(VK_END) & 0x01)
        {
            settings::cheats.showMenu = false;

            FreeLibraryAndExitThread(instance, 0);
            // TODO: remove ImGui or the game crashes
        }

        if (settings::cheats.showMenu && !GUIThreadHandle)
        {
            GUIThreadHandle = CreateThread(NULL, 0, &GUIThread, NULL, 0, 0);
        }
        else if (!settings::cheats.showMenu && GUIThreadHandle)
        {
            GUIThreadHandle = {};
        }

        if(settings::cheats.debug)
        {
            AllocConsole();

            FILE* fDummy;

            freopen_s(&fDummy, "CONOUT$", "w", stderr);
            freopen_s(&fDummy, "CONOUT$", "w", stdout);
        }

        context::playerData = (PlayerData*)memory::getAddress();

        features->autoshoot.run();
        features->debugmode.run();
        features->firepower.run();
        features->ingamecheats.run();
        features->shield.run();

        Sleep(10);
    }
}
