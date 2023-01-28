#pragma once

#include "../Settings.h"


class AutoShoot {
public:
    HANDLE AutoShootThreadHandle{};
    void run(Settings* settings);
};
