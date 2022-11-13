#pragma once
#include <windows.h>
#include <vector>


namespace offsets
{
	extern uintptr_t moduleBase = (uintptr_t)GetModuleHandle(NULL);

	extern uintptr_t lasersLevelPtr = moduleBase + 0x0005B1D0;
	std::vector<unsigned int> lasersLevelOffsets = { 0x298, 0x38, 0xC4  };
}
