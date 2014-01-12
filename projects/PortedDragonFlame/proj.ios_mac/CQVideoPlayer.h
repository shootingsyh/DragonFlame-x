#ifndef __CQVIDEOPLAYER_H__
#define __CQVIDEOPLAYER_H__

#include <cocos2d.h>
#include <CoreFoundation/CoreFoundation.h>

class CQVideoPlayer
{
public:
    
    bool init(); 
	static CQVideoPlayer* sharedVideoPlayer();
    ~CQVideoPlayer();
    
    void playVideo(const std::string& strFileName, std::string& strExtension);
    void stopVideo();
    
    static void notificationHandler(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo);
    void videoFinishedCallback();
};

#endif  // __CQVIDEOPLAYER_H__