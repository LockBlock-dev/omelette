#pragma once
#include <dinput.h> // Keyboard mapping from DirectInput


namespace settings {
	inline struct Cheats
	{
		bool showMenu = false;
		int playerId = 0;

		bool autoShoot = false;
		int autoShootKey = DIKEYBOARD_RSHIFT;
		int shootDelay = 100;

		bool customLasersLevel = false;
		int lasersLevel = 0;

		bool shield = false;
		int shieldTimeout = 100;
	} cheats;
}
