#pragma once


namespace settings {
	struct Cheats
	{
		bool showMenu = false;
		bool autoShoot = false;
		int shootDelay = 100;
	};

	inline auto cheats = Cheats{ };
}
