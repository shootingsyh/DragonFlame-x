#include "CQVideoPlayerHelper.h"

@implementation CQVideoPlayerHelper

- (id) initWithCPPInstance:(CQVideoPlayer*)cppInstance
{
    self = [super init];
    if (self) {
        m_VideoPlayer = cppInstance;
    }
    return self;
}

-(void)movieWindowTouched:(UIControl*)sender
{
    if (m_VideoPlayer) m_VideoPlayer->stopVideo();
}

@end

