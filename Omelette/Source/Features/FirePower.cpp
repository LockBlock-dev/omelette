#include "FirePower.h"
#include "../context.h"


void FirePower::run(Settings* settings)
{
    if (settings->customLasersLevel)
    {       
        PlayerData *playerData = Context::playerData;

        int* addr = (int*)&playerData->firepower;

        if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = settings->firepower;
        }
    }
}
