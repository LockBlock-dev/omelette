#include "lasers_level.h"
#include "../settings.h"
#include "../context.h"


void LasersLevel::run()
{
    if (settings::cheats.customLasersLevel)
    {       
        PlayerData* playerData = context::playerData;

        int* addr = (int*)&playerData->lasersLevel;

        if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = settings::cheats.lasersLevel;
        }
    }
}
