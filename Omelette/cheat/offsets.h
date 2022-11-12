#pragma once
#include <windows.h>
#include <vector>


namespace offsets
{
	inline uintptr_t moduleBase = (uintptr_t)GetModuleHandle(NULL);

	inline uintptr_t lasersLevelAddr = 0x0005B1D0;
	inline uintptr_t lasersLevelPtr = moduleBase + lasersLevelAddr;
	std::vector<unsigned int> lasersLevelOffset = { 0x298, 0x38, 0xC4  };
}
