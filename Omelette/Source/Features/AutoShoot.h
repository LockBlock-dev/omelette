#pragma once
#include <Windows.h>


class AutoShoot {
public:
    void run(DWORD cbData, LPVOID lpvData);
private:
    bool lastPoll;
};
