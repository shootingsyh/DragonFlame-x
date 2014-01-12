//
//  VideoPlayer.h
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/4/14.
//
//

#ifndef PortedDragonFlame_VideoPlayer_h
#define PortedDragonFlame_VideoPlayer_h
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "CQVideoPlayer.h"
#endif

class VideoPlayer : public cocos2d::Object {
public:
    
    void                            playVideo(std::string vidPath, std::string vidExt);
    
    static VideoPlayer             *getShared();
};


#endif
