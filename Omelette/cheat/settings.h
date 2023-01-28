#pragma once
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h> // Keyboard mapping from DirectInput


namespace settings {
	inline struct Cheats
	{
		bool showMenu = false;
		bool debug = false;

		int playerId = 1; // Player Blue/Left: 0; Player Red/Right: 1;

		bool inGameCheats = false;
		bool debugMode = false;

		bool autoShoot = false;
		int autoShootKey = DIKEYBOARD_RSHIFT; // Player Blue/Left: DIKEYBOARD_LSHIFT; Player Red/Right: DIKEYBOARD_RSHIFT;
		int shootDelay = 100;

		bool customLasersLevel = false;
		int firepower = 0;

		bool shield = false;
		int shieldTimeout = 100;
	} cheats;
}
