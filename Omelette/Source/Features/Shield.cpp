#include "Shield.h"
#include "../Context.h"
#include "../Settings.h"


void Shield::run()
{
    Settings& settings = Settings::getInstance();

    if (settings.shield)
    {
        PlayerData *playerData = Context::playerData;
        
        if (playerData) {
            int* addr = (int*)&playerData->shieldTimeout;

            if (addr) // Prevents crash when player dies (address is freed)
            {
                *addr = settings.shieldTimeout;
            }
        }
    }
}
