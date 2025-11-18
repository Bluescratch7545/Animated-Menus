#include <Geode/Geode.hpp>
#ifndef GEODE_IS_IOS
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

#include "../includes/version.hpp"

using namespace keybinds;

$execute {
    BindManager::get()->registerBindable({
        "open-settings-am"_spr,
        "Animated Menus: Open Settings",
        "Open Animated Menus Settings",
        { Keybind::create(KEY_F8, Modifier::None) },
        "Animated Menus/Open Settings"
    });

    new EventListener([=](InvokeBindEvent* event) {
        if (event->isDown()) {
            geode::createQuickPopup(
                "Animated Menus",
                "Do You Want To Open The Settings Menu?",
                "No", "Yes",
                [](auto, bool btn2) {
                    if (btn2) {
                        openSettingsPopup(Mod::get(), false);
                        log::info("Settings_Menu::STATE: Open");
                    }
                }
            );
        }
        return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "open-settings-am"_spr));

    BindManager::get()->registerBindable({
        "show-version"_spr,
        "Animated Menus: Show Newest Version",
        "Show Newest Version",
        { Keybind::create(KEY_F9, Modifier::None)},
        "Animated Menus/Show Version"
    });

    new EventListener([=](InvokeBindEvent* event) {
        if (event->isDown()) {
            FLAlertLayer::create(
                "Animated Menus",
                fmt::format("Newest Version Is: \n<cg>{}</c>", version),
                "OK"
            )->show();
        }
        return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "show-version"_spr));
};
#endif