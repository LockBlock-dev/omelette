#include "Rockets.h"
#include "../Context.h"


void Rockets::run()
{
    PlayerData *playerData = Context::playerData;
        
    if (playerData) {
        int* addr = (int*)&playerData->rocketsCount;

        if (addr) // Prevents crash when player dies (address is freed)
        {
            *addr += 1;
        }
    }
}
