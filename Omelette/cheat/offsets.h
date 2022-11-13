#pragma once
#include <windows.h>
#include <vector>


namespace offsets
{
	inline uintptr_t moduleBase = (uintptr_t)GetModuleHandle(NULL);

	// Player red/right/2
	inline uintptr_t playerData = moduleBase + 0x0005B1D0;

	inline std::vector<unsigned int> xCoordsOffsets = { 0x298, 0x38, 0x94 };
	inline std::vector<unsigned int> yCoordsOffsets = { 0x298, 0x38, 0x98 };
	inline std::vector<unsigned int> horizontalVelocity = { 0x298, 0x38, 0x9C };
	inline std::vector<unsigned int> invincibilityTimeoutOffsets = { 0x298, 0x38, 0xBC };
	inline std::vector<unsigned int> healthOffsets = { 0x298, 0x38, 0xC0 };
	inline std::vector<unsigned int> lasersLevelOffsets = { 0x298, 0x38, 0xC4 };
	inline std::vector<unsigned int> rocketsCountOffsets = { 0x298, 0x38, 0xC8 };
	inline std::vector<unsigned int> scoreOffsets = { 0x298, 0x38, 0xD4 };
}
