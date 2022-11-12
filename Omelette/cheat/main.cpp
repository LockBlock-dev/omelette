#include <dinput.h> // Keyboard mapping from DirectInput

#include "main.h"
#include "gui.h"
#include "settings.h"
#include "utils.h"

#include "features/auto_shoot.h"


DWORD WINAPI GUIThread(LPVOID param)
{
    // Create GUI
    gui::CreateHWindow(L"Omelette");
    gui::CreateDevice();
    gui::CreateImGui();

    while (true)
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

void cheat::start()
{
    HANDLE GUIThreadHandle{};

    while (true)
    {
        if (GetAsyncKeyState(VK_INSERT) & 0x01)
        {
            settings::cheats.showMenu = !settings::cheats.showMenu;
        }

        if (settings::cheats.showMenu && !GUIThreadHandle)
        {
            GUIThreadHandle = CreateThread(NULL, 0, &GUIThread, NULL, 0, 0);
        }
        else if (!settings::cheats.showMenu && GUIThreadHandle)
        {
            TerminateThread(GUIThreadHandle, 0);
            GUIThreadHandle = {};
        }

        AutoShoot::run();

        Sleep(100);
    }
}
