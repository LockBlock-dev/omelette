#include "Utils.h"


char gameName[17] = "Chicken Invaders";

INPUT makeKey(int directInputCode, bool up) // https://stackoverflow.com/a/71629807
{
    INPUT SHIFT;

    SHIFT.type = INPUT_KEYBOARD;
    SHIFT.ki.wVk = 0;
    SHIFT.ki.wScan = directInputCode;
    SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE;
    SHIFT.ki.dwExtraInfo = 0;
    SHIFT.ki.time = 0;

    if (up)
    {
        SHIFT.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    }

    return SHIFT;
}

bool isFocused()
{
    HWND foregroundWindow = GetForegroundWindow();
    char windowTitle[255];
    GetWindowTextA(foregroundWindow, windowTitle, 255);

    if (strcmp(windowTitle, gameName) == 0)
    {
        return true;
    }

    return false;
}

uintptr_t getPtrAddr(uintptr_t ptr, std::vector<uintptr_t> offsets)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        addr = *(uintptr_t*)addr;
        addr += offsets[i];
    }
    return addr;
}

void logStateBool(std::string label, bool* val, bool* oldVal)
{
    if (*oldVal != *val)
    {
        *oldVal = *val;
        std::cout << "[" << label << "] set to: " << (*val ? "enabled" : "disabled") << std::endl;;
    }
}

void logStateInt(std::string label, int val)
{
    std::cout << "[" << label << "] set to: " << val << std::endl;
}

void logStateFloat(std::string label, float val)
{
    std::cout << "[" << label << "] set to: " << val << std::endl;
}
