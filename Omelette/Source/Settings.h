#pragma once

#define DIRECTINPUT_VERSION 0x0700
#include <dinput.h> // Keyboard mapping from DirectInput

class Settings {
public:
    static Settings& getInstance() {
        static Settings instance;
        return instance;
    }

	bool showMenu = false;

	int playerId = 1; // Player Blue/Left: 0; Player Red/Right: 1;

	bool inGameCheats = false;
	bool debugMode = false;

	bool autoShoot = false;
	unsigned int autoShootKey = DIK_RSHIFT; // Player Blue/Left: DIKEYBOARD_LSHIFT; Player Red/Right: DIKEYBOARD_RSHIFT;
	int autoShootDelay = 100;

	bool customFirepower = false;
	int firepower = 0;

	bool shield = false;
	int shieldTimeout = 100;

private:
    Settings(); // Private constructor
};
