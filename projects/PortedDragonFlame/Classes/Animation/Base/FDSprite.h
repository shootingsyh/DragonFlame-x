//
//  FDSprite.h
//  FlameDragon
//
//  Created by sui toney on 11-11-5.
//  Copyright 2011 ms. All rights reserved.
//
#ifndef PortedDragonFlame_FDSprite_h
#define PortedDragonFlame_FDSprite_h

#include "cocos2d.h"

class FDImage;
class FDSprite: public cocos2d::Object {
public:
    bool init(std::string filename);
    bool init(std::string filename, cocos2d::Rect& rect);
    bool init(FDImage* image, cocos2d::Rect& rect);
    bool init(std::string str, int size);
    bool init(FDSprite * sprite);
    
    cocos2d::Sprite* getSprite();

    void setSprite(cocos2d::Sprite *s);
    void setImage(FDImage *image, bool sizeChanged=false);

    void setFrame(std::string fileName);

    void setOpacity(int o);
    void setColor(int r, int g, int b);
    void setVisible(bool visible);

    void addSprite(FDSprite *s, int order);
    void removeSprite(FDSprite *s);
    void updateZOrder(int zorder);

    void addToLayer(cocos2d::Layer *layer);
    void removeFromLayer();

    const cocos2d::Point& getLocation();
    void setLocation(const cocos2d::Point& loc);

    cocos2d::Size getSize();

    void setScale(float x, float y);
    void setAnchorPoint(const cocos2d::Point& pos);

    cocos2d::Point getScale();
    
    virtual ~FDSprite();
private:
    cocos2d::Sprite* ccsprite;
};

#endif