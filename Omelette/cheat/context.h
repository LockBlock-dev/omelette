#pragma once
#include <windows.h>
#include <vector>


#pragma pack(push, 1)
struct GameInfo;
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

namespace context {
	inline uintptr_t moduleBase = (uintptr_t)GetModuleHandle(NULL);
	inline unsigned int baseOffset = 0x0005B1D0;

	inline GameInfo* gameInfo = nullptr;
	inline std::vector<unsigned int> inGameCheats = { 0x298, 0x64 };
	inline PlayerData* playerData = nullptr;
}
