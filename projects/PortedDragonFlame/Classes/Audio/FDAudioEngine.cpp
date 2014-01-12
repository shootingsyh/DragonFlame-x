//
//  FDAudioEngine.cpp
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/12/14.
//
//

#include "FDAudioEngine.h"
#include "SimpleAudioEngine.h"
#include <sstream>
using namespace std;
using namespace CocosDenshion;
USING_NS_CC;

void FDAudioEngine::playTitleMusic() {
    SimpleAudioEngine::getInstance()->playBackgroundMusic("Title.mp3");
}

void FDAudioEngine::playEndingMusic() {
    SimpleAudioEngine::getInstance()->playBackgroundMusic("Ending.mp3");
    
}

void FDAudioEngine::playShopMusic(AudioShopType type) {
    
    switch (type) {
        case AudioShopType::AudioShopType_Amor:
            SimpleAudioEngine::getInstance()->playBackgroundMusic("ShopAmor.mp3");
            break;
        case AudioShopType::AudioShopType_Item:
            SimpleAudioEngine::getInstance()->playBackgroundMusic("ShopItem.mp3");
            break;
        case AudioShopType::AudioShopType_Church:
            SimpleAudioEngine::getInstance()->playBackgroundMusic("ShopChurch.mp3");
            break;
        case AudioShopType::AudioShopType_Bar:
            SimpleAudioEngine::getInstance()->playBackgroundMusic("ShopBar.mp3");
            break;
        default:
            break;
    }
}

void FDAudioEngine::playVillageMusic(int chapterId) {
    SimpleAudioEngine::getInstance()->playBackgroundMusic("Village_1.mp3");
}

void FDAudioEngine::playBattleGroundMusic(int chapterId) {
    
    if (chapterId == 31 || chapterId == 32) {
        return;
    }
    
    int musicId = 1;
    
    switch (chapterId) {
        case 1:  musicId = 2; break;
        case 2:  musicId = 1; break;
        case 3:  musicId = 2; break;
        case 4:  musicId = 1; break;
        case 5:  musicId = 2; break;
        case 6:  musicId = 1; break;
        case 7:  musicId = 2; break;
        case 8:  musicId = 1; break;
        case 9:  musicId = 2; break;
        case 10: musicId = 3; break;
        case 11: musicId = 2; break;
        case 12: musicId = 3; break;
        case 13: musicId = 3; break;
        case 14: musicId = 2; break;
        case 15: musicId = 3; break;
        case 16: musicId = 2; break;
        case 17: musicId = 3; break;
        case 18: musicId = 2; break;
        case 19: musicId = 3; break;
        case 20: musicId = 5; break;
        case 21: musicId = 3; break;
        case 22: musicId = 5; break;
        case 23: musicId = 3; break;
        case 24: musicId = 5; break;
        case 25: musicId = 3; break;
        case 26: musicId = 5; break;
        case 27: musicId = 4; break;
        case 28: musicId = 4; break;
        case 29: musicId = 4; break;
        case 30: musicId = 4; break;
        default:
            musicId = 1;
            break;
    }
    stringstream tempString;
    tempString <<"Battle_"<<musicId;

    SimpleAudioEngine::getInstance()->playBackgroundMusic(tempString.str().c_str());
}

void FDAudioEngine::stopMusic() {
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}


void FDAudioEngine::resumeAudio() {
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void FDAudioEngine::pauseAudio() {
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}