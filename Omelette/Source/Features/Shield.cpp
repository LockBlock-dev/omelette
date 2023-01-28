#include "Shield.h"
#include "../Context.h"


void Shield::run(Settings* settings)
{
    if (settings->shield)
    {
        PlayerData *playerData = Context::playerData;
        
        int* addr = (int*)&playerData->shieldTimeout;

        if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *addr = settings->shieldTimeout;
        }
    }
}
