#include "lives.h"
#include "../Context.h"


void Lives::run()
{
    PlayerData *playerData = Context::playerData;
        
    if (playerData) {
        int* addr = (int*)&playerData->lives;

        if (addr) // Prevents crash when player dies (address is freed)
        {
            *addr += 1;
        }
    }
}
