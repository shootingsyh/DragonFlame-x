#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
//
//  Constants.h
//  FlameDragon
//
//  Created by yonghong shi 2014-1-4.
//  Copyright 2014 ms. All rights reserved.
//

#include "cocos2d.h"


class Constants
{
public:
    static const int unitSize = 24;
    static const int tickLength = 30;

    static const int FPS = 60;

    constexpr static const float battleMapScale = 1.5;
    constexpr static const float villageScale = 1.5;
    constexpr static const float commonScale = 1.5;

    static const int fightAnimationIntervalUnit = 110;

    static int maxPickedFriendCount(int chapterId) {
        return (chapterId <= 26 ? 16 : 20);
    }
};
#endif
