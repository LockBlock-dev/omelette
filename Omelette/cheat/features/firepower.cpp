#include "firepower.h"
#include "../settings.h"
#include "../context.h"


void Firepower::run()
{
    if (settings::cheats.customLasersLevel)
    {       
        PlayerData *playerData = context::playerData;

        int* addr = (int*)&playerData->firepower;

        if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = settings::cheats.firepower;
        }
    }
}
