#include "lasers_level.h"
#include "../settings.h"
#include "../utils.h"
#include "../offsets.h"

void LasersLevel::run()
{
    if (settings::cheats.customLasersLevel)
    {       
        unsigned int* laserLevelAddr = (unsigned int*)getPtrAddr(offsets::playerRed, offsets::lasersLevelOffsets);

        if (laserLevelAddr > (unsigned int*)offsets::moduleBase) // Prevents crash when player dies (address is freed)
        { 
            *laserLevelAddr = settings::cheats.lasersLevel;
        }
        
    }
}
