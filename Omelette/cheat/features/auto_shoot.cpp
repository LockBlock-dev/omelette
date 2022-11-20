#include "auto_shoot.h"
#include "../utils.h"
#include "../settings.h"


void safeExit()
{
    INPUT SHIFT_UP = makeKey(settings::cheats.autoShootKey, true); // Failsafe: prevent the key to be hold down by Windows
    SendInput(1, &SHIFT_UP, sizeof(INPUT));
}

void autoShoot()
{
    INPUT SHIFT = makeKey(settings::cheats.autoShootKey); // https://stackoverflow.com/a/71629807

    SendInput(1, &SHIFT, sizeof(INPUT));

    Sleep(50); // The game won't detect the input if the delay is too short

    SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

    SendInput(1, &SHIFT, sizeof(INPUT));
}

DWORD WINAPI AutoShootThread(LPVOID param)
{
    while (true)
    {
        bool hasFocus = isFocused();

        if (settings::cheats.autoShoot && hasFocus)
        {
            autoShoot();
        }
        else if (!hasFocus)
        {
            safeExit(); // When the focus is lost the key should be released
        }

        Sleep(settings::cheats.shootDelay);
    }

    return 0;
}

HANDLE AutoShootThreadHandle{};

void AutoShoot::run()
{
    if (settings::cheats.autoShoot && !AutoShootThreadHandle)
    {
        AutoShootThreadHandle = CreateThread(NULL, 0, &AutoShootThread, NULL, 0, 0);
    }
    else if (!settings::cheats.autoShoot && AutoShootThreadHandle)
    {
        CloseHandle(AutoShootThreadHandle);
        AutoShootThreadHandle = {};

        safeExit();  // When disabling the autoShoot the key should be released
    }
}
