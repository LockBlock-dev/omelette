#include "invincibility.h"
#include "../settings.h"
#include "../utils.h"
#include "../offsets.h"

void Invincibility::run()
{
    if (settings::cheats.invincibility)
    {
        unsigned int* invincibilityTimeoutAddr = (unsigned int*)getPtrAddr(offsets::playerData, offsets::invincibilityTimeoutOffsets);

        if (invincibilityTimeoutAddr > (unsigned int*)offsets::moduleBase) // Prevents crash when player dies (address is freed)
        {
            *invincibilityTimeoutAddr = settings::cheats.invincibilityTimeout;
        }

    }
}
