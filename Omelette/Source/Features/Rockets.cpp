#include "Rockets.h"
#include "../Context.h"


void Rockets::run()
{
    PlayerData *playerData = context::playerData;
        
    int* addr = (int*)&playerData->rocketsCount;

    if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
    {
        *addr += 1;
    }
}
