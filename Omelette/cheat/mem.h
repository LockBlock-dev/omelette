#pragma once
#include "utils.h"
#include "settings.h"
#include "context.h"


namespace memory
{
	uintptr_t getAddress() {
		if (settings::cheats.playerId == 0)
		{
			// Player Blue/Left
			return getPtrAddr(context::moduleBase + context::baseOffset, { 0x298, 0x34, 0 });
		}
		else {
			// Player Red/Right
			return getPtrAddr(context::moduleBase + context::baseOffset, { 0x298, 0x38, 0 });
		}
	}
}
