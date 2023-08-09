#include "FirePower.h"
#include "../Context.h"
#include "../Settings.h"

void FirePower::run()
{
    Settings& settings = Settings::getInstance();

    if (settings.customFirepower)
    {       
        PlayerData *playerData = Context::playerData;

        if (playerData) {
            int* addr = (int*)&playerData->firepower;

            if (addr) // Prevents crash when player dies (address is freed)
            {
                *addr = settings.firepower;
            }
        }
    }
}
