#include "shield.h"
#include "../settings.h"
#include "../context.h"


void Shield::run()
{
    if (settings::cheats.shield)
    {
        PlayerData *playerData = context::playerData;
        
        int* addr = (int*)&playerData->shieldTimeout;

        if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = settings::cheats.shieldTimeout;
        }
    }
}
