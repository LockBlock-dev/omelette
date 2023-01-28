#include "lives.h"
#include "../Context.h"


void Lives::run()
{
    PlayerData *playerData = Context::playerData;
        
    int* addr = (int*)&playerData->lives;

    if (addr > (int*)Context::moduleBase) // Prevents crash when player dies (address is freed)
    {
        *addr += 1;
    }
}
