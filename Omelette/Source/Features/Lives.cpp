#include "lives.h"
#include "../Context.h"


void Lives::run()
{
    PlayerData *playerData = context::playerData;
        
    int* addr = (int*)&playerData->lives;

    if (addr > (int*)context::moduleBase) // Prevents crash when player dies (address is freed)
    {
        *addr += 1;
    }
}
