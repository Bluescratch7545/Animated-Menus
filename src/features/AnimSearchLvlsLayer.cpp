#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

#include "../includes/settings.hpp"

class $modify(AnimLevelSearchLayer, LevelSearchLayer) {
    $override
    bool init(int type) {
        if (!LevelSearchLayer::init(type)) return false;

        // Works If enable is true
        if(enable()) {
            // Define difficultyFMenu
            auto difficultyFMenu = getChildByID("difficulty-filter-menu");

            // Move it
            float startDFMX = 1000.0f;
            auto difficultyFMenuYPos = difficultyFMenu->getPositionY();
            float targetDFMX = difficultyFMenu->getPositionX();
            
            // Start it off screen
            difficultyFMenu->setPositionX(startDFMX);

            // Define movement
            auto mnuDFMMoveAction = CCMoveTo::create(speed(), CCPoint{targetDFMX, difficultyFMenuYPos});
            auto easeMnuDFMMoveAction = CCEaseBackOut::create(mnuDFMMoveAction);

            // Run action
            difficultyFMenu->runAction(easeMnuDFMMoveAction);

            // Define quickSearchMenu
            auto quickSearchMenu = getChildByID("quick-search-menu");

            // Move it
            float startQSMX = 1000.0f;
            auto quickSearchMenuYPos = quickSearchMenu->getPositionY();
            auto targetQSMX = quickSearchMenu->getPositionX();

            // Start it off screen
            quickSearchMenu->setPositionX(startQSMX);

            // Define movement
            auto mnuQSMMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{targetQSMX, quickSearchMenuYPos});
            auto easeMnuQSMMoveAction = CCEaseBackOut::create(mnuQSMMoveAction);

            // Run action
            quickSearchMenu->runAction(easeMnuQSMMoveAction);

            // Define lengthFilterMenu
            auto lengthFilterMenu = getChildByID("length-filter-menu");

            // Move it
            float startLFMX = 1000.0f;
            auto lengthFilterMenuYPos = lengthFilterMenu->getPositionY();
            auto targetLFMX = lengthFilterMenu->getPositionX();

            // Start it off screen 
            lengthFilterMenu->setPositionX(startLFMX);

            // Define movement
            auto mnuLFMMoveAction = CCMoveTo::create(speed() + 1.0f, CCPoint{targetLFMX, lengthFilterMenuYPos});
            auto easeMnuLFMMoveAction = CCEaseBackOut::create(mnuLFMMoveAction);

            // Run action
            lengthFilterMenu->runAction(easeMnuLFMMoveAction);

            // define searchButtonMenu
            auto searchButtonMenu = getChildByID("search-button-menu");

            // Move it
            float startSBMY = 500.0f;
            auto searchButtonMenuXPos = searchButtonMenu->getPositionX();
            auto targetSBMY = searchButtonMenu->getPositionY();

            // Start it off screen
            searchButtonMenu->setPositionY(startSBMY);

            // Define movement
            auto mnuSBMMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{searchButtonMenuXPos, targetSBMY});
            auto easeMnuSBMMoveAction = CCEaseExponentialOut::create(mnuSBMMoveAction);

            // Run action
            searchButtonMenu->runAction(easeMnuSBMMoveAction);

            // Define searchBar and levelSearchBarBG
            auto searchBar = getChildByID("search-bar");
            auto levelSearchBarBG = getChildByID("level-search-bar-bg");

            // Move them
            float startSBY = 500.0f;
            auto searchBarXPos = searchBar->getPositionX();
            auto levelSearchBarBGXPos = levelSearchBarBG->getPositionX();
            auto targetSBY = searchBar->getPositionY();
            auto targetLSBBGY = levelSearchBarBG->getPositionY();

            // Start them off screen
            searchBar->setPositionY(startSBY);
            levelSearchBarBG->setPositionY(startSBY);

            // Define movement
            auto txtFldSBMoveAction = CCMoveTo::create(speed() + 0.75f, CCPoint{searchBarXPos, targetSBY});
            auto sprLSBBGMoveAction = CCMoveTo::create(speed() + 0.75f, CCPoint{levelSearchBarBGXPos, targetLSBBGY});
            auto easeTxtFldSBMoveAction = CCEaseBackOut::create(txtFldSBMoveAction);
            auto easeSprLSBBGMoveAction = CCEaseBackOut::create(sprLSBBGMoveAction);

            // Run actions
            searchBar->runAction(easeTxtFldSBMoveAction);
            levelSearchBarBG->runAction(easeSprLSBBGMoveAction);

            // Define otherFilterMenu
            auto otherFilterMenu = getChildByID("other-filter-menu");

            // Move it
            float startOFMX = 1000.0f;
            auto otherFilterMenuYPos = otherFilterMenu->getPositionY();
            auto targetOFMX = otherFilterMenu->getPositionX();

            // Start it off scren
            otherFilterMenu->setPositionX(startOFMX);

            // Define movement
            auto mnuOFMMoveAction = CCMoveTo::create(speed() + 2.0f, CCPoint{targetOFMX, otherFilterMenuYPos});
            auto easeMnuOFMMOveAction = CCEaseBackOut::create(mnuOFMMoveAction);

            // Run action
            otherFilterMenu->runAction(easeMnuOFMMOveAction);
        }
        
        return true;
    }
};