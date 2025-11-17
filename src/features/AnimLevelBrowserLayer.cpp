#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>

using namespace geode::prelude;

#include "../includes/settings.hpp"

class $modify(AnimLevelBrowserLayer, LevelBrowserLayer) {
    $override
    bool init(GJSearchObject* object) {
        if (!LevelBrowserLayer::init(object)) return false;

        if(enable()) {
            // Define GJListLayer
            auto GJListLayer = getChildByID("GJListLayer");

            // Move it
            float startGJLLY = 1000.0f;
            auto GJListLayerXPos = GJListLayer->getPositionX();
            auto targetGJLLY = GJListLayer->getPositionY();

            // Start it off screen
            GJListLayer->setPositionY(startGJLLY);

            // Define movement
            auto lyrGJLLMoveAction = CCMoveTo::create(speed(), CCPoint{GJListLayerXPos, targetGJLLY});
            auto easeLyrGJLLMoveAction = CCEaseBackOut::create(lyrGJLLMoveAction);

            // Run action
            GJListLayer->runAction(easeLyrGJLLMoveAction);

            // Define deleteMenu
            auto deleteMenu = getChildByID("delete-menu");

            // Move it
            float startDMY = 1000.0f;
            auto deleteMenuXPos = deleteMenu->getPositionX();
            auto targetDMY = deleteMenu->getPositionY();

            // Start it off screen
            deleteMenu->setPositionY(startDMY);

            // Define movement
            auto mnuDMMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{deleteMenuXPos, targetDMY});
            auto easeMnuDMMoveAction = CCEaseBackOut::create(mnuDMMoveAction);

            // Run action
            deleteMenu->runAction(easeMnuDMMoveAction);

            // Define selectAllText
            auto selectAllText = getChildByID("select-all-text");

            // Move it
            float startSATY = 1000.0f;
            auto selectAllTextXPos = selectAllText->getPositionX();
            auto targetSATY = selectAllText->getPositionY();

            // Start it off screen
            selectAllText->setPositionY(startSATY);

            // Define movement
            auto txtSATMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{selectAllTextXPos, targetSATY});
            auto easeTxtSATMoveAction = CCEaseBackOut::create(txtSATMoveAction);

            // Run action
            selectAllText->runAction(easeTxtSATMoveAction);
        }
        
        return true;
    }
};

// GJListLayer