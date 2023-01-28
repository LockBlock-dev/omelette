#pragma once
#include "Utils.h"
#include "Context.h"


namespace memory
{
	uintptr_t getAddress(int playerId) {
		if (playerId == 0)
		{
			// Player Blue/Left
			return getPtrAddr(Context::moduleBase + Context::baseOffset, { 0x298, 0x34, 0 });
		}
		else if (playerId == 1) {
			// Player Red/Right
			return getPtrAddr(Context::moduleBase + Context::baseOffset, { 0x298, 0x38, 0 });
		}
	}
}
