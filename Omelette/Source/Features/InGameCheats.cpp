#include "InGameCheats.h"
#include "../Settings.h"
#include "../Context.h"
#include "../Utils.h"


void InGameCheats::run()
{
    if (settings::cheats.inGameCheats)
    {
        int* addr = (int*)getPtrAddr(context::moduleBase + context::baseOffset, context::inGameCheats);

        if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 257;
        }
    }
    else
    {
        int* addr = (int*)getPtrAddr(context::moduleBase + context::baseOffset, context::inGameCheats);

        if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 1;
        }
    }
}
