#include <Geode/Geode.hpp>
#ifndef GEODE_IS_IOS
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;
using namespace keybinds;

$execute {
    BindManager::get()->registerBindable({
        "open-settings-bm"_spr,
        "Better Menus: Open Settings",
        "Open Better Menus Settings",
        { Keybind::create(KEY_F8, Modifier::None) },
        "Better Menus/Open Settings"
    });

    new EventListener([=](InvokeBindEvent* event) {
        if (event->isDown()) {
            openSettingsPopup(Mod::get(), false);
            log::info("Settings_Menu::STATE: Open");
        }
        return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "open-settings-bm"_spr));
};
#endif