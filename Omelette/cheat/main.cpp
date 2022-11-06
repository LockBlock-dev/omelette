#include <dinput.h> // Keyboard mapping from DirectInput
#include <iostream>

#include "main.h"

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
        if (autoShootEnabled && isFocused())
        {
            autoShoot();
        }

        Sleep(100);
    }

    return 0;
}

void cheat::start()
{
    HANDLE spamThreadHandle{};

    while (true)
    {
        if (GetAsyncKeyState(VK_F1) && 1)
        {
            if (autoShootEnabled && spamThreadHandle)
            {
                TerminateThread(spamThreadHandle, 0);

                std::cout << "Spam stopped" << std::endl;

                INPUT SHIFT_UP = makeKey(DIKEYBOARD_RSHIFT, true); // Failsafe: prevent the key to be hold down by Windows
                SendInput(1, &SHIFT_UP, sizeof(INPUT));
            }
            else
            {
                spamThreadHandle = CreateThread(NULL, 0, &SpamThread, NULL, 0, 0);

                std::cout << "Spam started" << std::endl;
            }

            autoShootEnabled = !autoShootEnabled;
        }

        Sleep(500);
    }
}