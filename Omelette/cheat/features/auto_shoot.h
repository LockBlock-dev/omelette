#pragma once


namespace AutoShoot {
	void run();

	struct State
	{
		HANDLE AutoShootThread{};
	} state;
}
