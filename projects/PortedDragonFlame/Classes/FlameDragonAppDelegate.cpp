//
//  FlameDragonAppDelegate.m
//  FlameDragon
//
//  Created by sui toney on 11-11-1.
//  Copyright ms 2011. All rights reserved.
//

#include "cocos2d.h"

#include "FlameDragonAppDelegate.h"
#include "Constants.h"
#include "VideoPlayer.h"
#include "ObjectHelper.h"
#include "TitleScene.h"
#include "FDAudioEngine.h"

USING_NS_CC;

/*
#include "GameConfig.h"
#include "HelloWorldScene.h"
#include "MainGameScene.h"
#include "DataDepot.h"
#include "GameOverScene.h"
 */

bool FlameDragonAppDelegate::applicationDidFinishLaunching()
{
	// initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();
    
    director->setOpenGLView(eglView);
	
    // turn on display FPS
    director->setDisplayStats(false);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(Constants::tickLength / 1000.0);

    Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::RGBA8888);
    auto frameSize = eglView->getFrameSize();
    eglView->setDesignResolutionSize(480, 320, ResolutionPolicy::NO_BORDER);
    /*
	// Load Global Information
	[[DataDepot depot] loadAllDictionaries];
	
	
     */
	
    // Start Movie
    VideoPlayer::getShared()->playVideo("Openning", "mp4");// Run the intro Scene
	director->runWithScene(create<TitleScene>());
    return true;
}

void FlameDragonAppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();
    FDAudioEngine::pauseAudio();
}

void FlameDragonAppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();
    FDAudioEngine::resumeAudio();
}

