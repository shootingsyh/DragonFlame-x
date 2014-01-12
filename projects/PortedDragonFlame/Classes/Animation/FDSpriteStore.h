//
//  FDSpriteStore.h
//  FlameDragon
//
//  Created by sui toney on 11-11-3.
//  Copyright 2011 ms. All rights reserved.
//
#ifndef PortedDragonFlame_FDSpriteStore_h
#define PortedDragonFlame_FDSpriteStore_h

#include "cocos2d.h"
#include "FDImage.h"
#include "FDSprite.h"

class FDSpriteStore : public cocos2d::Object {
public:
    FDSpriteStore();
    ~FDSpriteStore();
    static FDSpriteStore* instance;
    static FDSpriteStore* getInstance();

    FDImage *getImage(std::string fileName);
    FDSprite *getSprite(std::string fileName);
    
private:
    cocos2d::Dictionary *spriteDictionary;
    cocos2d::Dictionary *imageDictionary;
    
};

#endif