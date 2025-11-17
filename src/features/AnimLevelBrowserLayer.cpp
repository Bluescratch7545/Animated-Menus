#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>

using namespace geode::prelude;

#include "../includes/settings.hpp"

class $modify(AnimLevelBrowserLayer, LevelBrowserLayer) {
    $override
    bool init(GJSearchObject* object) {
        if (!LevelBrowserLayer::init(object)) return false;

        if(enable()) {
            auto GJListLayer = getChildByID("GJListLayer");

            // GJLL is GJListLayer
            float startGJLLY = 1000.0f;
            auto GJListLayerXPos = GJListLayer->getPositionX();
            auto targetGJLLY = GJListLayer->getPositionY();

            GJListLayer->setPositionY(startGJLLY);

            auto lyrGJLLMoveAction = CCMoveTo::create(speed(), CCPoint{GJListLayerXPos, targetGJLLY});
            auto easeLyrGJLLMoveAction = CCEaseBackOut::create(lyrGJLLMoveAction);

            GJListLayer->runAction(easeLyrGJLLMoveAction);

            if(auto deleteMenu = getChildByID("delete-menu")) {
                // DM is deleteMenu
                float startDMY = 1000.0f;
                auto deleteMenuXPos = deleteMenu->getPositionX();
                auto targetDMY = deleteMenu->getPositionY();

                deleteMenu->setPositionY(startDMY);

                auto mnuDMMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{deleteMenuXPos, targetDMY});
                auto easeMnuDMMoveAction = CCEaseBackOut::create(mnuDMMoveAction);

                deleteMenu->runAction(easeMnuDMMoveAction);

                auto selectAllText = getChildByID("select-all-text");

                // SAT is selectAllText
                float startSATY = 1000.0f;
                auto selectAllTextXPos = selectAllText->getPositionX();
                auto targetSATY = selectAllText->getPositionY();

                selectAllText->setPositionY(startSATY);

                auto txtSATMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{selectAllTextXPos, targetSATY});
                auto easeTxtSATMoveAction = CCEaseBackOut::create(txtSATMoveAction);

                selectAllText->runAction(easeTxtSATMoveAction);
            }
        }
        
        return true;
    }
};