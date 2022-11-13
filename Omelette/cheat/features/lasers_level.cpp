#include "lasers_level.h"
#include "../settings.h"
#include "../utils.h"
#include "../offsets.h"

void LasersLevel::run()
{
    if (settings::cheats.customLasersLevel)
    {       
        int* laserLevelAddr = (int*)getPtrAddr(offsets::lasersLevelPtr, offsets::lasersLevelOffsets);

        if (laserLevelAddr > (int*)offsets::moduleBase) // Prevents crash when player dies (address is freed)
        { 
            *laserLevelAddr = settings::cheats.lasersLevel;
        }
        
    }
}
