#include "AutoShoot.h"
#include "../Utils.h"


void safeExit(Settings* settings)
{
    INPUT SHIFT_UP = makeKey(settings->autoShootKey, true); // Failsafe: prevent the key to be hold down by Windows
    SendInput(1, &SHIFT_UP, sizeof(INPUT));
}

void autoShoot(Settings* settings)
{
    INPUT SHIFT = makeKey(settings->autoShootKey); // https://stackoverflow.com/a/71629807

    SendInput(1, &SHIFT, sizeof(INPUT));

    Sleep(50); // The game won't detect the input if the delay is too short

    SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

    SendInput(1, &SHIFT, sizeof(INPUT));
}

DWORD WINAPI AutoShootThread(LPVOID param)
{
    Settings* settings = (Settings*)param;

    while (settings->autoShoot)
    {
        bool hasFocus = isFocused();

        if (settings->autoShoot && hasFocus)
        {
            autoShoot(settings);
        }
        else if (!hasFocus)
        {
            safeExit(settings); // When the focus is lost the key should be released
        }

        Sleep(settings->autoShootDelay);
    }

    return 0;
}

void AutoShoot::run(Settings* settings)
{
    if (settings->autoShoot && !this->AutoShootThreadHandle)
    {
        this->AutoShootThreadHandle = CreateThread(NULL, 0, &AutoShootThread, settings, 0, 0);
    }
    else if (!settings->autoShoot && this->AutoShootThreadHandle)
    {
        CloseHandle(this->AutoShootThreadHandle);
        this->AutoShootThreadHandle = {};
    
        safeExit(settings);  // When disabling the autoShoot the key should be released
    }
}
