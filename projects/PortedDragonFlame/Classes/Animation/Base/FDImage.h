//
//  FDImage.h
//  FlameDragon
//
//  Created by sui toney on 11-11-5.
//  Copyright 2011 ms. All rights reserved.
//
#ifndef PortedDragonFlame_FDImage_h
#define PortedDragonFlame_FDImage_h

#include "cocos2d.h"

class FDImage: public cocos2d::Object {
public:
    virtual ~FDImage();
    bool init(std::string fileName);
    bool init(cocos2d::Texture2D* tex);

    cocos2d::Texture2D* texture;
};
#endif