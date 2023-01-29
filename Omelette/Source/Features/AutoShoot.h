#pragma once

#include "../Settings.h"


class AutoShoot {
public:
    void run(Settings* settings);
private:
    HANDLE AutoShootThreadHandle{};
    std::string name = "AutoShoot";
};
