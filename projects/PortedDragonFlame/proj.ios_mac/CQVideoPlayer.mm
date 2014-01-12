#include "CQVideoPlayer.h"
#include "CQVideoPlayerHelper.h"
#import <MediaPlayer/MediaPlayer.h>

static CQVideoPlayer *pSharedVideoPlayer = NULL;

// Keep these pointers to shut everything down in the end
MPMoviePlayerViewController *playerViewController;
MPMoviePlayerController *player;
UIControl* overlay;
CQVideoPlayerHelper *helper;
UIWindow *window;

CQVideoPlayer* CQVideoPlayer::sharedVideoPlayer()
{
    if (! pSharedVideoPlayer)
    {
        pSharedVideoPlayer = new CQVideoPlayer();
        pSharedVideoPlayer->init();
    }

    return pSharedVideoPlayer;
}

bool CQVideoPlayer::init()
{
    // Some black magik to hear objC notifications from C++ class
    CFNotificationCenterAddObserver(CFNotificationCenterGetLocalCenter(), this, &notificationHandler, (CFStringRef)MPMoviePlayerPlaybackDidFinishNotification,  NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
	return true;
}

void CQVideoPlayer::playVideo(const std::string& strFileName, std::string& strExtension)
{
    // Init MPMoviePlayerViewController
    NSString *url = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:strFileName.c_str()] ofType:[NSString stringWithUTF8String:strExtension.c_str()]];
    playerViewController = [[MPMoviePlayerViewController alloc] initWithContentURL:[NSURL fileURLWithPath:url]];
    
    // Same thing we're doing in AppController
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    [window addSubview: playerViewController.view];
    [window makeKeyAndVisible];
    
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        [window addSubview: playerViewController.view];
    }
    else
    {
        [window setRootViewController:playerViewController];
    }
    
    // Actually start a video
    player = [playerViewController moviePlayer];
    [player prepareToPlay];
    player.scalingMode = MPMovieScalingModeAspectFill;
    player.shouldAutoplay = TRUE;
    player.controlStyle = MPMovieControlStyleNone;
    [player play];
    
    // The movie's window is the one that is active
    overlay = [[[UIControl alloc] initWithFrame:window.frame] autorelease];
    
    // We want to get notified whenever the overlay control is touched
    helper = [[[CQVideoPlayerHelper alloc] initWithCPPInstance:this] retain];
    [overlay addTarget:helper action:@selector(movieWindowTouched:) forControlEvents:UIControlEventTouchDown];
    
    // Add the overlay to the window's subviews
    [window addSubview:overlay];
    
}

// React to notification
void CQVideoPlayer::notificationHandler(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo)
{
    (static_cast<CQVideoPlayer *>(observer))->videoFinishedCallback();
}

void CQVideoPlayer::stopVideo()
{
    if ([player playbackState] == MPMoviePlaybackStatePlaying) [player stop];
}

void CQVideoPlayer::videoFinishedCallback()
{
    // Hide video
    [player.view removeFromSuperview];
    [overlay removeFromSuperview];
    [window setHidden:YES];
    [window release];
    [playerViewController release];
    [helper release];
    CCLOG("GOT HERE");
    // Post a notification to be able to properly react
    cocos2d::CCNotificationCenter::sharedNotificationCenter()->postNotification("VideoPlaybackFinished");
}

CQVideoPlayer::~CQVideoPlayer()
{
    // Remove observer in the end
    CFNotificationCenterRemoveEveryObserver(CFNotificationCenterGetLocalCenter(), this);
}

