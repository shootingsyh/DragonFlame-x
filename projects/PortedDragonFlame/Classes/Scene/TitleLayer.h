//
//  TitleLayer.h
//  FlameDragon
//
//  Created by sui toney on 11-12-27.
//  Copyright 2011 ms. All rights reserved.
//

#include "cocos2d.h"
// #include "CreatureRecord.h"


#ifndef PortedDragonFlame_TitleLayer_h
#define PortedDragonFlame_TitleLayer_h

class TitleLayer : public cocos2d::Layer {
public:
    virtual bool init();
    
private:
    void onNewGame();
    void onLoadGame();
    void onContinueGame();
    
    bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

private:
    bool clickedOnButton(const cocos2d::Point& buttonLoc, const cocos2d::Point& clickedLoc);
    
    cocos2d::Scene * loadTestingGame();
    //CreatureRecord * loadTestingRecord:(int)creatureId level:(int)level;
};

#endif