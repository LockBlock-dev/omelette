#pragma once
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h> // Keyboard mapping from DirectInput
#include <vector>
#include <iostream>


INPUT makeKey(int directInputCode, bool up = false);
bool isFocused();
uintptr_t getPtrAddr(uintptr_t ptr, std::vector<uintptr_t> offsets);
void logStateBool(std::string label, bool* val, bool* oldVal);
void logStateInt(std::string label, int val);
void logStateFloat(std::string label, float val);
