#include "FirePower.h"
#include "../Context.h"


void FirePower::run(Settings* settings)
{
    if (settings->customFirepower)
    {       
        PlayerData *playerData = Context::playerData;

        int* addr = (int*)&playerData->firepower;

        if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = settings->firepower;
        }
    }
}
