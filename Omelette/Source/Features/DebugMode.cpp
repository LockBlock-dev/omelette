#include "DebugMode.h"
#include "../Context.h"
#include "../Utils.h"


void DebugMode::run(Settings* settings)
{
    if (settings->debugMode)
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::debugMode);

        if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 2;
        }
    }
    else
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::debugMode);

        if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 0;
        }
    }
}
