#pragma once
#include <windows.h>


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
	inline PlayerData* playerData = nullptr;
}

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
