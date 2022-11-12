#include <dinput.h> // Keyboard mapping from DirectInput

#include "auto_shoot.h"
#include "../utils.h"
#include "../settings.h"


void safeExit()
{
    INPUT SHIFT_UP = utils::makeKey(DIKEYBOARD_RSHIFT, true); // Failsafe: prevent the key to be hold down by Windows
    SendInput(1, &SHIFT_UP, sizeof(INPUT));
}

void autoShoot()
{
    INPUT SHIFT = utils::makeKey(DIKEYBOARD_RSHIFT); // https://stackoverflow.com/a/71629807

    SendInput(1, &SHIFT, sizeof(INPUT));

    Sleep(50); // The game won't detect the input if the delay is too short

    SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

    SendInput(1, &SHIFT, sizeof(INPUT));
}

DWORD WINAPI AutoShootThread(LPVOID param)
{
    while (true)
    {
        bool isFocused = utils::isFocused();

        if (settings::cheats.autoShoot && isFocused)
        {
            autoShoot();
        }
        else if (!isFocused)
        {
            safeExit(); // When the focus is lost the key should be released
        }

        Sleep(settings::cheats.shootDelay);
    }

    return 0;
}

void AutoShoot::run()
{
    if (settings::cheats.autoShoot && !AutoShoot::state.AutoShootThread)
    {
        AutoShoot::state.AutoShootThread = CreateThread(NULL, 0, &AutoShootThread, NULL, 0, 0);
    }
    else if (!settings::cheats.autoShoot && AutoShoot::state.AutoShootThread)
    {
        TerminateThread(AutoShoot::state.AutoShootThread, 0);
        AutoShoot::state.AutoShootThread = {};

        safeExit();  // When disabling the autoShoot the key should be released
    }
}
