#include <dinput.h> // Keyboard mapping from DirectInput

#include "main.h"
#include "gui.h"
#include "settings.h"

#include "features/auto_shoot.h"
#include "features/lasers_level.h"
#include "features/shield.h"


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

        AutoShoot::run();
        LasersLevel::run();
        Shield::run();

        //Sleep(100);
    }
}
