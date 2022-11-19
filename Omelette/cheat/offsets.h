#pragma once
#include <windows.h>
#include <vector>


namespace offsets
{
	inline uintptr_t moduleBase = (uintptr_t)GetModuleHandle(NULL);

	// Player blue/left
	inline uintptr_t playerBlue = getPtrAddr(moduleBase + 0x0005B1D0, { 0x298, 0x34, 0x94 });
	// Player red/right
	inline uintptr_t playerRed = getPtrAddr(moduleBase + 0x0005B1D0, { 0x298, 0x38, 0x94 });

	/*
	inline std::vector<unsigned int> xCoordsOffsets = { 0x94 };
	inline std::vector<unsigned int> yCoordsOffsets = { 0x98 };
	inline std::vector<unsigned int> horizontalVelocity = { 0x9C };
	inline std::vector<unsigned int> shieldTimeoutOffsets = { 0xBC };
	inline std::vector<unsigned int> healthOffsets = { 0xC0 };
	inline std::vector<unsigned int> lasersLevelOffsets = { 0xC4 };
	inline std::vector<unsigned int> rocketsCountOffsets = { 0xC8 };
	inline std::vector<unsigned int> scoreOffsets = { 0xD4 };
	*/

	#pragma pack(push, 1)
	struct PlayerData {
		int x;
		int y;
		int xVelocity; // -10 (left), 0 (idle), 10 (right)
		unsigned int playerId; // Blue = 0, Red = 1
		unsigned int spaceshipAngle; // 0 (left), 4 (idle), 8 (right)
		char _unk1[4]; // unknown
		char _unk2[4]; // unknown
		char _unk3[4]; // unknown
		int shieldPulseEffect; // -1 = close wide bubble, 1 = thin distant bubble
		unsigned int invisibilityTimeout;
		unsigned int shieldTimeout;
		unsigned int lives;
		unsigned int lasersLevel; // 0 to 7
		unsigned int rocketsCount;
		unsigned int chickensAte;
		unsigned int scoreDisplay; // grows slowly
		unsigned int score; // instant
	};
	#pragma pack(pop)

	inline PlayerData* playerBlueData = (PlayerData*)playerBlue;
	inline PlayerData* playerRedData = (PlayerData*)playerRed;
}
