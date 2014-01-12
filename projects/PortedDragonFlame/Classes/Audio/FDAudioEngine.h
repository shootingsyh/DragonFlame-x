//
//  FDAudioEngine.h
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/12/14.
//
//

#ifndef __PortedDragonFlame__FDAudioEngine__
#define __PortedDragonFlame__FDAudioEngine__

#include "cocos2d.h"

enum class AudioShopType {
    AudioShopType_Amor,
    AudioShopType_Item,
    AudioShopType_Church,
    AudioShopType_Bar
};

class FDAudioEngine {
public:
    static void playTitleMusic();
    static void playEndingMusic();
    static void playShopMusic(AudioShopType type);
    static void playVillageMusic(int chapterId);
    static void playBattleGroundMusic(int chapterId);
    static void stopMusic();
    
    static void resumeAudio();
    static void pauseAudio();
};

#endif /* defined(__PortedDragonFlame__FDAudioEngine__) */
