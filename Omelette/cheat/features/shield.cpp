#include "shield.h"
#include "../settings.h"
#include "../utils.h"
#include "../offsets.h"


void Shield::run()
{
    if (settings::cheats.shield)
    {
        unsigned int* shieldTimeoutAddr = (unsigned int*)getPtrAddr(offsets::playerData, offsets::shieldTimeoutOffsets);

        if (shieldTimeoutAddr > (unsigned int*)offsets::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *shieldTimeoutAddr = settings::cheats.shieldTimeout;
        }

    }
}
