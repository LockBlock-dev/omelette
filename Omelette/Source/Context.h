#pragma once
#include <windows.h>
#include <vector>


#pragma pack(push, 1)
struct PlayerData {
	char _unk1[36]; // unknown
	double size; // spaceship size default to 1
	int _unk3;
	int axis; // 0 = default, 2 mirrored vertical, 4 = mirrored horizontal
	char _unk4[96];
	int x;
	int y;
	int xVelocity; // -10 (left), 0 (idle), 10 (right)
	int playerId; // Blue = 0, Red = 1
	int spaceshipAngle; // 0 (left), 4 (idle), 8 (right)
	int _unk5;
	int _unk6;
	int _unk7;
	int shieldPulseEffect; // -1 = close wide bubble, 1 = thin distant bubble
	int invisibilityTimeout;
	int shieldTimeout;
	int lives;
	int firepower; // 0 to 7
	int rocketsCount;
	int consumedChickenLegs;
	int scoreDisplay; // grows slowly
	int score; // instant
};
#pragma pack(pop)

#pragma pack(push, 1)
struct ChickenData {
	int x;
	int y;
	char _unk1[12];
	double size; // chicken size default to 1
	int _unk2;
	int axis; // 0 = default, 2 mirrored vertical, 4 = mirrored horizontal
	char _unk3[92];
	int health;
	int spawnTimeout;
	int xBase;
	int yBase;
	int x_2;
	int y_2;
	char _unk4[12];
	int movements; // 0 = idle, 1 = moving

};
#pragma pack(pop)

namespace Context {
	inline uintptr_t moduleBase = (uintptr_t)GetModuleHandle(NULL);
	inline unsigned int baseOffset = 0x5B1D0;

	inline std::vector<unsigned int> inGameCheats = { 0x298, 0x64 };
	inline std::vector<unsigned int> debugMode = { 0x4D0 };
	inline PlayerData* playerData = nullptr;
}
