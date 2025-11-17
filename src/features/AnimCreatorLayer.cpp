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
            auto winSize = CCDirector::sharedDirector()->getWinSize();

            auto creatorButtonsMenu = getChildByID("creator-buttons-menu");

            float startY = -1000.0f;
            auto creatorButtonsMenuXPos = creatorButtonsMenu->getPositionX();
            float targetY = winSize.height / 2;

            creatorButtonsMenu->setPositionY(startY);

            auto grpCBMMoveAction = CCMoveTo::create(speed() + 0.5, CCPoint{creatorButtonsMenuXPos, targetY});
            auto easeGrpCBMMoveAction = CCEaseBackOut::create(grpCBMMoveAction);

            creatorButtonsMenu->runAction(easeGrpCBMMoveAction);

            auto topLeftCorner = getChildByID("top-left-corner");
            auto topRightCorner = getChildByID("top-right-menu");

            // T is top
            // TL is topLeft
            // TR is topRight
            float startTY = 500.0f;
            auto topLeftCornerXPos = topLeftCorner->getPositionX();
            float targetTLY = 321.0f;
            auto topRightCornerXPos = topRightCorner->getPositionX();
            float targetTRY = 244.750f;

            topLeftCorner->setPositionY(startTY);
            topRightCorner->setPositionY(startTY);

            auto sprTLCMoveAction = CCMoveTo::create(speed() + 1.0f, CCPoint{topLeftCornerXPos, targetTLY});
            auto grpTRMoveAction = CCMoveTo::create(speed() + 1.5f, CCPoint{topRightCornerXPos, targetTRY});
            auto easeSprTLMoveAction = CCEaseExponentialOut::create(sprTLCMoveAction);
            auto easeGrpTRMoveAction = CCEaseBackOut::create(grpTRMoveAction);

            topLeftCorner->runAction(easeSprTLMoveAction);
            topRightCorner->runAction(easeGrpTRMoveAction);

            auto exitMenu = getChildByID("exit-menu");

            // EM is exitMenu
            float startEMY = 400.0f;
            auto exitMenuXPos = exitMenu->getPositionX();
            float targetEMY = 254.50f;

            exitMenu->setPositionY(startEMY);

            auto btnEMMoveAction = CCMoveTo::create(speed() + 2.0f, CCPoint{exitMenuXPos, targetEMY});
            auto easeBtnEMMoveAction = CCEaseBackOut::create(btnEMMoveAction);

            exitMenu->runAction(easeBtnEMMoveAction);

            auto bottomLeftCorner = getChildByID("bottom-left-corner");
            auto bottomRightCorner = getChildByID("bottom-right-menu");

            // B is bottom
            // BL is bottomLeft
            // BR is bottomRight
            float startBY = -100.0f;
            float targetBLY = -1.0f;
            float targetBRY = 62.250f;
            auto bottomRightCornerXPos = bottomRightCorner->getPositionX();
            auto bottomLeftCornerXPos = bottomLeftCorner->getPositionX();

            bottomLeftCorner->setPositionY(startBY);
            bottomRightCorner->setPositionY(startBY);

            auto sprBLCMoveAction = CCMoveTo::create(speed() + 1.5f, CCPoint{bottomLeftCornerXPos, targetBLY});
            auto btnBRMMoveAction = CCMoveTo::create(speed() + 1.0f, CCPoint{bottomRightCornerXPos, targetBRY});
            auto easeSprBLCMoveAction = CCEaseExponentialOut::create(sprBLCMoveAction);
            auto easeBtnBRMMoveAction = CCEaseBackOut::create(btnBRMMoveAction);

            bottomLeftCorner->runAction(easeSprBLCMoveAction);
            bottomRightCorner->runAction(easeBtnBRMMoveAction);
        }

        return true;
    }
};