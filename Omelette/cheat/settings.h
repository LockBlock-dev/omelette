#pragma once

namespace settings {
	struct Cheats
	{
		bool showMenu = false;
		bool autoShoot = false;
	};

	inline auto cheats = Cheats{ };
}