#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h> // Keyboard mapping from DirectInput


class Settings {
public:
	bool showMenu = false;
	bool debug = false;

	int playerId = 1; // Player Blue/Left: 0; Player Red/Right: 1;

	bool inGameCheats = false;
	bool debugMode = false;

	bool autoShoot = false;
	unsigned int autoShootKey = DIKEYBOARD_RSHIFT; // Player Blue/Left: DIKEYBOARD_LSHIFT; Player Red/Right: DIKEYBOARD_RSHIFT;
	int autoShootDelay = 100;

	bool customFirepower = false;
	int firepower = 0;

	bool shield = false;
	int shieldTimeout = 100;
};
