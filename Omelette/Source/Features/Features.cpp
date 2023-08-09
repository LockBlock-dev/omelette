#include "Features.h"

FeaturesManager::FeaturesManager() {
    this->autoshoot = AutoShoot{};
    this->debugmode = DebugMode{};
    this->firepower = FirePower{};
    this->ingamecheats = InGameCheats{};
    this->lives = Lives{};
    this->rockets = Rockets{};
    this->shield = Shield{};
}
