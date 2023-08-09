#include "InGameCheats.h"
#include "../Context.h"
#include "../Utils.h"
#include "../Settings.h"

void InGameCheats::run()
{
    Settings& settings = Settings::getInstance();

    if (settings.inGameCheats)
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::inGameCheats);

        if (addr) // Prevents crash when player dies (address is freed)
        {
            *addr = 1;
        }
    }
    else
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::inGameCheats);

        if (addr) // Prevents crash when player dies (address is freed)
        {
            *addr = 0;
        }
    }
}
