#ifndef __CQVIDEOPLAYERHELPER_H__
#define __CQVIDEOPLAYERHELPER_H__

#include "CQVideoPlayer.h"

@interface CQVideoPlayerHelper : NSObject{
    CQVideoPlayer *m_VideoPlayer;
}

- (id) initWithCPPInstance:(CQVideoPlayer*)cppInstance;
-(void)movieWindowTouched:(UIControl*)sender;

@end

#endif  // __CQVIDEOPLAYERHELPER_H__