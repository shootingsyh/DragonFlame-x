//
//  TitleLayer.m
//  FlameDragon
//
//  Created by sui toney on 11-12-27.
//  Copyright 2011 ms. All rights reserved.
//

#include "TitleLayer.h"
#include "Constants.h"
#include "FDWindow.h"
#include "FDAudioEngine.h"

#include "FDSpriteStore.h"
/*
#import "MainGameScene.h"
#import "FDWindow.h"
#import "GameRecord.h"
#import "VillageScene.h"
#import "LoadingScene.h"
#import "FDAudioEngine.h"
#import "GameWinScene.h"
*/

USING_NS_CC;
using namespace std::placeholders;

bool TitleLayer::init()
{
    Layer::init();
	
	FDSprite *bg = FDSpriteStore::getInstance()->getSprite("Title.png");
	bg->setScale(Constants::commonScale, Constants::commonScale);
	bg->setLocation(FDWindow::getScreenCenter());
	
	FDSprite *startButton = FDSpriteStore::getInstance()->getSprite("Title_Start_1.png");
	startButton->setScale(Constants::commonScale, Constants::commonScale);
	startButton->setLocation(FDWindow::getTitleButtonStart());
	
	FDSprite *loadButton = FDSpriteStore::getInstance()->getSprite("Title_Load_1.png");
	loadButton->setScale(Constants::commonScale, Constants::commonScale);
	loadButton->setLocation(FDWindow::getTitleButtonLoad());
	
	FDSprite *continueButton = FDSpriteStore::getInstance()->getSprite("Title_Continue_1.png");
	continueButton->setScale(Constants::commonScale, Constants::commonScale);
	continueButton->setLocation(FDWindow::getTitleButtonContinue());
	
	addChild(bg->getSprite());
	addChild(startButton->getSprite());
	addChild(loadButton->getSprite());
	addChild(continueButton->getSprite());
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = std::bind(&TitleLayer::touchBegan, this, _1, _2);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
    //[CCVideoPlayer setDelegate:self];
    
    FDAudioEngine::playTitleMusic();
    
	return true;
}

bool TitleLayer::touchBegan(Touch* touch, Event* event) {
	Point location = touch->getLocationInView();
	Point clickedLoc = Director::getInstance()->convertToGL(location);
	
    if (this->clickedOnButton(FDWindow::getTitleButtonStart(), clickedLoc)) {
		this->onNewGame();
	}
	else if (this->clickedOnButton(FDWindow::getTitleButtonLoad(), clickedLoc)) {
		this->onLoadGame();
	}
	else if (this->clickedOnButton(FDWindow::getTitleButtonContinue(), clickedLoc)) {
		this->onContinueGame();
	}
    return true;
}

bool TitleLayer::clickedOnButton(const Point& buttonLoc, const Point& clickedLoc) {
	return (clickedLoc.x > buttonLoc.x - 80 && clickedLoc.x < buttonLoc.x + 80 && 
			clickedLoc.y > buttonLoc.y - 20 && clickedLoc.y < buttonLoc.y + 20);
}

void TitleLayer::onNewGame()
{
	CCLOG("onNewGame");
	
	////GameStartInfo *info = [[ChapterRecord alloc] initWithChapter:1];
    //GameStartInfo *info = [[ChapterRecord alloc] initWithChapter:99];
	
	//MainGameScene *mainGame = [MainGameScene node];
	//[mainGame loadWithInfo:info];
	
	//[[CCDirector sharedDirector] pushScene: [CCTransitionFade transitionWithDuration:1.0 scene:mainGame]];
    
    //[FDAudioEngine stopMusic];
    
    //[info release];
}

void TitleLayer::onLoadGame()
{
	CCLOG("onLoadGame");
	
	//CCScene *scene = [self loadTestingGame];
    //CCScene *scene = [GameWinScene node];
    ////LoadingScene *scene = [LoadingScene node];
    
	////[[CCDirector sharedDirector] pushScene: [CCTransitionFade transitionWithDuration:1.0 scene:scene]];
    
    ////[FDAudioEngine stopMusic];
}

void TitleLayer::onContinueGame()
{
	CCLOG("onContinueGame");
	
	//GameStartInfo *info = [[GameLoadedInfo alloc] initWithLevel:1];
	//GameStartInfo *info = [[GameLoadedInfo alloc] readFromFile:nil];
	
	////GameRecord *record = [GameRecord readFromSavedFile];
	////GameStartInfo *info = [record.battleRecord retain];
	//[record saveRecord];
	/*
	if (info.chapterId > 0) {
		
		[FDAudioEngine stopMusic];
    
        MainGameScene *mainGame = [MainGameScene node];
		[mainGame loadWithInfo:info];
	
		[[CCDirector sharedDirector] pushScene: [CCTransitionFade transitionWithDuration:1.0 scene:mainGame]];
	}
	
	[info release];
    */
}

Scene* TitleLayer::loadTestingGame()
{
    /*
	ChapterRecord *record = [ChapterRecord generateRecord:27 money:60000];
	
    for (int i = 1; i <= 27; i++) {
        [[record friendRecords] addObject:[self loadTestingRecord:i level:99]];
	}
	
	VillageScene *scene = [VillageScene node];
	[scene loadWithRecord:record];
	
    return scene;
    */
    return nullptr;
}
/*
-(CreatureRecord *) loadTestingRecord:(int)creatureId level:(int)level
{
	FDFriend *creature = [[FDFriend alloc] initWithDefinition:creatureId Id:creatureId];
	
	for (int i = creature.data.level; i < level; i++) {
		[creature levelUp];
	}
	
	CreatureRecord *r = [[CreatureRecord alloc] init];
	r.creatureId = [creature getIdentifier];
	r.definitionId = [[creature getDefinition] getId];
	r.creatureType = [creature getCreatureType];
	
	r.data = [creature.data clone];
	r.data.hpCurrent = r.data.hpMax;
	r.data.mpCurrent = r.data.mpMax;
	
    if (r.creatureId == 1) {
        [r.data.itemList addObject:[NSNumber numberWithInt:811]];
    }
    if (r.creatureId == 3) {
        [r.data.itemList addObject:[NSNumber numberWithInt:809]];
    }
    
	[creature release];
	
	return [r autorelease];
}
 */
/*
-(void) moviePlaybackFinished {
    CCLOG(@"moviePlaybackFinished");
    [[CCDirector sharedDirector] stopAnimation];
}

-(void) movieStartsPlaying {
    CCLOG(@"");
    [[CCDirector sharedDirector] startAnimation];
}
*/

