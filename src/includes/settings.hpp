// Defines the settings once so that i dont have to define them 10000000000000 times

#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

inline int64_t speed() {
    return Mod::get()->getSettingValue<int64_t>("speed");
}

inline bool enable() {
    return Mod::get()->getSettingValue<bool>("enable-mod");
}