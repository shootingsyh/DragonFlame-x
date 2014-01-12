//
//  VideoPlayer.cpp
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/4/14.
//
//

#include "VideoPlayer.h"
static VideoPlayer *instance   =   NULL;

void VideoPlayer::playVideo(std::string vidPath, std::string ext) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CQVideoPlayer::sharedVideoPlayer()->playVideo(vidPath, ext);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    CCApplication::sharedApplication()->playVideo();
#endif
}

VideoPlayer *VideoPlayer::getShared() {
    if (!instance) {
        instance                =   new VideoPlayer();
    }
    return                          instance;
}