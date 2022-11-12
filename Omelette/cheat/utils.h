#pragma once
#include <dinput.h> // Keyboard mapping from DirectInput
#include <vector>


INPUT makeKey(int directInputCode, bool up = false);
bool isFocused();
uintptr_t getPtrAddr(uintptr_t ptr, std::vector<uintptr_t> offsets);