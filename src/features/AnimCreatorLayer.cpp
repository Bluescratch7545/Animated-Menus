#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

#include "../includes/settings.hpp"

class $modify(AnimCreatorLayer, CreatorLayer) {
    $override
    bool init() {
        if (!CreatorLayer::init()) return false;

        // If enable Is Not True, The Mod Will Not Work
        if (enable()) {
            // Define winSize
            auto winSize = CCDirector::sharedDirector()->getWinSize();

            // Define creatorButtonsMenu
            auto creatorButtonsMenu = getChildByID("creator-buttons-menu");

            // Move Center Buttons
            float startY = -1000.0f;
            auto creatorButtonsMenuXPos = creatorButtonsMenu->getPositionX();
            float targetY = winSize.height / 2;

            // Start Them Off-Screen
            creatorButtonsMenu->setPositionY(startY);

            // Define the movement
            auto grpCBMMoveAction = CCMoveTo::create(speed() + 0.5, CCPoint{creatorButtonsMenuXPos, targetY});
            auto easeGrpCBMMoveAction = CCEaseBackOut::create(grpCBMMoveAction);

            // Move Them
            creatorButtonsMenu->runAction(easeGrpCBMMoveAction);

            // Define topLeftCorner And topRightCorner
            auto topLeftCorner = getChildByID("top-left-corner");
            auto topRightCorner = getChildByID("top-right-menu");

            // Move Top Corners
            float startTY = 500.0f;
            auto topLeftCornerXPos = topLeftCorner->getPositionX();
            float targetTLY = 321.0f;
            auto topRightCornerXPos = topRightCorner->getPositionX();
            float targetTRY = 244.750f;

            // Move Them Off-screen
            topLeftCorner->setPositionY(startTY);
            topRightCorner->setPositionY(startTY);

            // Define the movements
            auto sprTLCMoveAction = CCMoveTo::create(speed() + 1.0f, CCPoint{topLeftCornerXPos, targetTLY});
            auto grpTRMoveAction = CCMoveTo::create(speed() + 1.5f, CCPoint{topRightCornerXPos, targetTRY});
            auto easeSprTLMoveAction = CCEaseExponentialOut::create(sprTLCMoveAction);
            auto easeGrpTRMoveAction = CCEaseBackOut::create(grpTRMoveAction);

            // Run Them
            topLeftCorner->runAction(easeSprTLMoveAction);
            topRightCorner->runAction(easeGrpTRMoveAction);

            // Define exitMenu
            auto exitMenu = getChildByID("exit-menu");

            // Move exitMenu
            float startEMY = 400.0f;
            auto exitMenuXPos = exitMenu->getPositionX();
            float targetEMY = 254.50f;

            // Move it off-screen
            exitMenu->setPositionY(startEMY);

            // Define The Movement
            auto btnEMMoveAction = CCMoveTo::create(speed() + 2.0f, CCPoint{exitMenuXPos, targetEMY});
            auto easeBtnEMMoveAction = CCEaseBackOut::create(btnEMMoveAction);

            // Run Movement
            exitMenu->runAction(easeBtnEMMoveAction);

            // Define bottomLeftCorner and bottomRightCorner
            auto bottomLeftCorner = getChildByID("bottom-left-corner");
            auto bottomRightCorner = getChildByID("bottom-right-menu");

            // Move them
            float startBY = -100.0f;
            float targetBLY = -1.0f;
            float targetBRY = 62.250f;
            auto bottomRightCornerXPos = bottomRightCorner->getPositionX();
            auto bottomLeftCornerXPos = bottomLeftCorner->getPositionX();

            // Start them off-screen
            bottomLeftCorner->setPositionY(startBY);
            bottomRightCorner->setPositionY(startBY);

            // Define the Movement
            auto sprBLCMoveAction = CCMoveTo::create(speed() + 1.5f, CCPoint{bottomLeftCornerXPos, targetBLY});
            auto btnBRMMoveAction = CCMoveTo::create(speed() + 1.0f, CCPoint{bottomRightCornerXPos, targetBRY});
            auto easeSprBLCMoveAction = CCEaseExponentialOut::create(sprBLCMoveAction);
            auto easeBtnBRMMoveAction = CCEaseBackOut::create(btnBRMMoveAction);

            // Run The Movement
            bottomLeftCorner->runAction(easeSprBLCMoveAction);
            bottomRightCorner->runAction(easeBtnBRMMoveAction);
        }

        return true;
    }
};