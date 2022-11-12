#include "lasers_level.h"
#include "../settings.h"
#include "../utils.h"
#include "../offsets.h"

void LasersLevel::run()
{
    if (settings::cheats.customLasersLevel)
    {       
        int* laserLevel = (int*)getPtrAddr(offsets::lasersLevelPtr, offsets::lasersLevelOffset);

        if (laserLevel > (int*)offsets::moduleBase) // Prevents crash when player dies (address is freed)
        { 
            *laserLevel = settings::cheats.lasersLevel;
        }
        
    }
}
