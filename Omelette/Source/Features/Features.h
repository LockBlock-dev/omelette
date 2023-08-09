#pragma once

#include "AutoShoot.h"
#include "DebugMode.h"
#include "FirePower.h"
#include "InGameCheats.h"
#include "Lives.h"
#include "Rockets.h"
#include "Shield.h"

class FeaturesManager {
public:
    static FeaturesManager& getInstance() {
        static FeaturesManager instance;
        return instance;
    }

    AutoShoot autoshoot;
    DebugMode debugmode;
    FirePower firepower;
    InGameCheats ingamecheats;
    Lives lives;
    Rockets rockets;
    Shield shield;

private:
    FeaturesManager(); // Private constructor
};
