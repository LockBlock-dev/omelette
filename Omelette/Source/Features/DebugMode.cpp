#include "DebugMode.h"
#include "../Context.h"
#include "../Utils.h"
#include "../Settings.h"

void DebugMode::run()
{
    Settings& settings = Settings::getInstance();

    if (settings.debugMode)
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::debugMode);

        if (addr) // Prevents crash when player dies (address is freed)
        {
            *addr = 2;
        }
    }
    else
    {
        int* addr = (int*)getPtrAddr(Context::moduleBase + Context::baseOffset, Context::debugMode);

        if (addr) // Prevents crash when player dies (address is freed)
        {
            *addr = 0;
        }
    }
}
