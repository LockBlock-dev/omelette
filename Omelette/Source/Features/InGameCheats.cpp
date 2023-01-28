#include "InGameCheats.h"
#include "../Context.h"
#include "../Utils.h"


void InGameCheats::run(Settings* settings)
{
    if (settings->inGameCheats)
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::inGameCheats);

        if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 257;
        }
    }
    else
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::inGameCheats);

        if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 1;
        }
    }
}
