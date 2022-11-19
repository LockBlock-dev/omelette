#pragma once


namespace settings {
	inline struct Cheats
	{
		bool showMenu = false;

		bool autoShoot = false;
		int shootDelay = 100;

		bool customLasersLevel = false;
		int lasersLevel = 0;

		bool shield = false;
		int shieldTimeout = 100;
	} cheats;
}
