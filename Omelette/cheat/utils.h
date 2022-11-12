#pragma once
#include <dinput.h> // Keyboard mapping from DirectInput


namespace utils
{
	INPUT makeKey(int directInputCode, bool up = false);

	bool isFocused();
}
