#define DIRECTINPUT_VERSION 0x0700
#include <dinput.h>

#include "AutoShoot.h"
#include "../Context.h"
#include "../Utils.h"
#include "../Settings.h"

void AutoShoot::run(DWORD cbData, LPVOID lpvData)
{
    Settings& settings = Settings::getInstance();

    if (settings.autoShoot)
    {
        constexpr int KEYBOARD_STATE_SIZE = 0x100;

        if (cbData == KEYBOARD_STATE_SIZE) {
            BYTE* keys = (BYTE*)lpvData;

            keys[settings.autoShootKey] = AutoShoot::lastPoll ? 0x0 : 0x80;

            AutoShoot::lastPoll = !AutoShoot::lastPoll;
        }
    }
}
