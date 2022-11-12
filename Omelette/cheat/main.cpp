#include <dinput.h> // Keyboard mapping from DirectInput
#include <iostream>

#include "main.h"
#include "gui.h"
#include "settings.h"


char gameName[17] = "Chicken Invaders";
bool autoShootEnabled = false;

INPUT makeKey(int directInputCode, bool up = false)
{
    INPUT SHIFT;

    SHIFT.type = INPUT_KEYBOARD;
    SHIFT.ki.wVk = 0;
    SHIFT.ki.wScan = directInputCode;
    SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE;
    SHIFT.ki.dwExtraInfo = 0;
    SHIFT.ki.time = 0;

    if (up)
    {
        SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    }

    return SHIFT;
}

void autoShoot()
{
    INPUT SHIFT = makeKey(DIKEYBOARD_RSHIFT); // https://stackoverflow.com/a/71629807

    SendInput(1, &SHIFT, sizeof(INPUT));

    Sleep(50); // The game won't detect the input if the delay is too short

    SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

    SendInput(1, &SHIFT, sizeof(INPUT));
}

bool isFocused()
{
    HWND foregroundWindow = GetForegroundWindow();
    char windowTitle[255];
    GetWindowTextA(foregroundWindow, windowTitle, 255);

    if (strcmp(windowTitle, gameName) == 0)
    {
        return true;
    }

    return false;
}

DWORD WINAPI SpamThread(LPVOID param)
{
    while (true)
    {
        std::cout << settings::cheats.autoShoot << isFocused() << std::endl;
        if (settings::cheats.autoShoot && isFocused())
        {
            autoShoot();
        }

        Sleep(100);
    }

    return 0;
}

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
    HANDLE spamThreadHandle{};

    while (true)
    {
        std::cout << settings::cheats.showMenu << std::endl;

        if (GetAsyncKeyState(VK_F1) && 1)
        {
            settings::cheats.showMenu = !settings::cheats.showMenu;
        }

        if (!settings::cheats.showMenu && GUIThreadHandle)
        {
            TerminateThread(GUIThreadHandle, 0); 
            GUIThreadHandle = {};
        }
        else if (settings::cheats.showMenu && !GUIThreadHandle)
        {
            GUIThreadHandle = CreateThread(NULL, 0, &GUIThread, NULL, 0, 0);
        }

        if (!settings::cheats.autoShoot && spamThreadHandle)
        {
            TerminateThread(spamThreadHandle, 0);
            spamThreadHandle = {};

            std::cout << "Spam stopped" << std::endl;

            INPUT SHIFT_UP = makeKey(DIKEYBOARD_RSHIFT, true); // Failsafe: prevent the key to be hold down by Windows
            SendInput(1, &SHIFT_UP, sizeof(INPUT));
        }
        else if (settings::cheats.autoShoot && !spamThreadHandle)
        {
            spamThreadHandle = CreateThread(NULL, 0, &SpamThread, NULL, 0, 0);

            std::cout << "Spam started" << std::endl;
        }

        Sleep(500);
    }
}