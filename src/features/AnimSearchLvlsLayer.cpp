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
            auto difficultyFilterMenu = getChildByID("difficulty-filter-menu");

            // DFM is difficultyFilterMenu
            float startDFMX = 1000.0f;
            auto difficultyFilterMenuYPos = difficultyFilterMenu->getPositionY();
            float targetDFMX = difficultyFilterMenu->getPositionX();
            
            difficultyFilterMenu->setPositionX(startDFMX);

            auto mnuDFMMoveAction = CCMoveTo::create(speed(), CCPoint{targetDFMX, difficultyFilterMenuYPos});
            auto easeMnuDFMMoveAction = CCEaseBackOut::create(mnuDFMMoveAction);

            difficultyFilterMenu->runAction(easeMnuDFMMoveAction);

            auto quickSearchMenu = getChildByID("quick-search-menu");

            // QSMX is quickSearchMenu
            float startQSMX = 1000.0f;
            auto quickSearchMenuYPos = quickSearchMenu->getPositionY();
            auto targetQSMX = quickSearchMenu->getPositionX();

            quickSearchMenu->setPositionX(startQSMX);

            // mnu is menu
            auto mnuQSMMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{targetQSMX, quickSearchMenuYPos});
            auto easeMnuQSMMoveAction = CCEaseBackOut::create(mnuQSMMoveAction);

            quickSearchMenu->runAction(easeMnuQSMMoveAction);

            auto lengthFilterMenu = getChildByID("length-filter-menu");

            // LFM is lengthFilterMenu
            float startLFMX = 1000.0f;
            auto lengthFilterMenuYPos = lengthFilterMenu->getPositionY();
            auto targetLFMX = lengthFilterMenu->getPositionX();

            lengthFilterMenu->setPositionX(startLFMX);

            auto mnuLFMMoveAction = CCMoveTo::create(speed() + 1.0f, CCPoint{targetLFMX, lengthFilterMenuYPos});
            auto easeMnuLFMMoveAction = CCEaseBackOut::create(mnuLFMMoveAction);

            lengthFilterMenu->runAction(easeMnuLFMMoveAction);

            auto searchButtonMenu = getChildByID("search-button-menu");

            // SBM is searchButtonMenu
            float startSBMY = 500.0f;
            auto searchButtonMenuXPos = searchButtonMenu->getPositionX();
            auto targetSBMY = searchButtonMenu->getPositionY();

            searchButtonMenu->setPositionY(startSBMY);

            auto mnuSBMMoveAction = CCMoveTo::create(speed() + 0.5f, CCPoint{searchButtonMenuXPos, targetSBMY});
            auto easeMnuSBMMoveAction = CCEaseExponentialOut::create(mnuSBMMoveAction);

            searchButtonMenu->runAction(easeMnuSBMMoveAction);

            auto searchBar = getChildByID("search-bar");
            auto levelSearchBarBG = getChildByID("level-search-bar-bg");

            // SB is search bar
            // LSBBG is levelSearchBarBG
            float startSBY = 500.0f;
            auto searchBarXPos = searchBar->getPositionX();
            auto levelSearchBarBGXPos = levelSearchBarBG->getPositionX();
            auto targetSBY = searchBar->getPositionY();
            auto targetLSBBGY = levelSearchBarBG->getPositionY();

            searchBar->setPositionY(startSBY);
            levelSearchBarBG->setPositionY(startSBY);

            auto txtFldSBMoveAction = CCMoveTo::create(speed() + 0.75f, CCPoint{searchBarXPos, targetSBY});
            auto sprLSBBGMoveAction = CCMoveTo::create(speed() + 0.75f, CCPoint{levelSearchBarBGXPos, targetLSBBGY});
            auto easeTxtFldSBMoveAction = CCEaseBackOut::create(txtFldSBMoveAction);
            auto easeSprLSBBGMoveAction = CCEaseBackOut::create(sprLSBBGMoveAction);

            searchBar->runAction(easeTxtFldSBMoveAction);
            levelSearchBarBG->runAction(easeSprLSBBGMoveAction);

            auto otherFilterMenu = getChildByID("other-filter-menu");

            // OFM is otherFilterMenu
            float startOFMX = 1000.0f;
            auto otherFilterMenuYPos = otherFilterMenu->getPositionY();
            auto targetOFMX = otherFilterMenu->getPositionX();

            otherFilterMenu->setPositionX(startOFMX);

            auto mnuOFMMoveAction = CCMoveTo::create(speed() + 2.0f, CCPoint{targetOFMX, otherFilterMenuYPos});
            auto easeMnuOFMMOveAction = CCEaseBackOut::create(mnuOFMMoveAction);

            otherFilterMenu->runAction(easeMnuOFMMOveAction);
        }
        
        return true;
    }
};