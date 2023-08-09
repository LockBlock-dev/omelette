#include <Windows.h>

#include "Utils.h"


bool isFocused()
{
    HWND foregroundWindow = GetForegroundWindow();
    WCHAR windowTitle[255];
    GetWindowText(foregroundWindow, windowTitle, 255);

    const WCHAR gameName[17] = L"Chicken Invaders";

    if (!wcscmp(windowTitle, gameName))
    {
        return true;
    }

    return false;
}

uintptr_t getPtrAddr(uintptr_t ptr, std::vector<uintptr_t> offsets)
{
    if (ptr == 0) {
        return -1;
    }

    uintptr_t addr = ptr;

    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        if (addr == 0) {
            return -1;
        }

        addr = *(uintptr_t*)addr;
        addr += offsets[i];
    }

    return addr;
}
