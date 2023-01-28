#include "Rockets.h"
#include "../Context.h"


void Rockets::run()
{
    PlayerData *playerData = Context::playerData;
        
    int* addr = (int*)&playerData->rocketsCount;

    if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
    {
        *addr += 1;
    }
}
