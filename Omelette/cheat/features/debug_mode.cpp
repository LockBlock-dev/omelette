#include "debug_mode.h"
#include "../settings.h"
#include "../context.h"
#include "../utils.h"


void DebugMode::run()
{
    if (settings::cheats.debugMode)
    {
        int* addr = (int*)getPtrAddr(context::moduleBase + context::baseOffset, context::debugMode);

        if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 2;
        }
    }
    else
    {
        int* addr = (int*)getPtrAddr(context::moduleBase + context::baseOffset, context::debugMode);

        if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = 0;
        }
    }
}
