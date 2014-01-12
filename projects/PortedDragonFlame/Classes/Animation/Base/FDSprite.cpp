//
//  FDSprite.m
//  FlameDragon
//
//  Created by sui toney on 11-11-5.
//  Copyright 2011 ms. All rights reserved.
//

#include "FDSprite.h"
#include "FDImage.h"
#include "Common.h"

using namespace std;
USING_NS_CC;

bool FDSprite::init(string fileName)
{
	ccsprite = Sprite::create(fileName);
    ccsprite->retain();
	
	// ccsprite.scaleX = 1.02;
	// ccsprite.scaleY = 1.02;
	
	return true;
}

bool FDSprite::init(FDImage *image, Rect& rect) {
    
    ccsprite = Sprite::createWithTexture(image->texture, rect);
    ccsprite->retain();
    return ccsprite;
}

bool FDSprite::init(string fileName, Rect& rect)
{
	/*
	CCSpriteBatchNode *batch = [CCSpriteBatchNode batchNodeWithFile:fileName capacity:12];
	ccsprite = [CCSprite spriteWithBatchNode:batch rect:rect];
	[ccsprite retain];
	*/
    ccsprite = Sprite::create(fileName, rect);
    ccsprite->retain();
    
	return ccsprite;
}

bool FDSprite::init(string str, int size)
{
	//CCLabelTTF *label = [CCLabelTTF labelWithString:str fontName:@"Marker Felt" fontSize:size];
	LabelTTF *ccsprite = LabelTTF::create(str, "Arial", size);
	ccsprite->setFontFillColor(Color3B(200, 200, 200));
    ccsprite->retain();
	
    /*
    CCLabelTTF *label2 = [CCLabelTTF labelWithString:str fontName:@"Arial" fontSize:size];
	label2.color = ccc3(200, 200, 200);
    label2.position = CGPointMake(-1,-1);
    label2.anchorPoint = CGPointMake(-1,-1);
	[ccsprite addChild:label2 z:1];
	*/
    
	return ccsprite;
}

bool FDSprite::init(FDSprite *sprite)
{
    if (sprite == nullptr || sprite->ccsprite == nullptr) {
        return false;
    }
	
    ccsprite = Sprite::createWithTexture(sprite->ccsprite->getTexture());
    ccsprite->retain();
    
	return ccsprite;
}

Sprite* FDSprite::getSprite()
{
	return ccsprite;
}

void FDSprite::addSprite(FDSprite *s, int order)
{
	ccsprite->addChild(s->getSprite(), order, 0);
}

void FDSprite::removeSprite(FDSprite *s)
{
	ccsprite->removeChild(s->getSprite(), false);
}

const Point& FDSprite::getLocation()
{
	return ccsprite->getOffsetPosition();
}

void FDSprite::setLocation(const Point& loc)
{
	ccsprite->setPosition(loc);
}

void FDSprite::updateZOrder(int zorder)
{
	ccsprite->getParent()->reorderChild(ccsprite, zorder);
}

Size FDSprite::getSize()
{
	return ccsprite->getBoundingBox().size;
}

void FDSprite::setOpacity(int o)
{
	ccsprite->setOpacity(o);
}

void FDSprite::setScale(float x, float y)
{
	ccsprite->setScaleX(x);
	ccsprite->setScaleY(y);
}

Point FDSprite::getScale()
{
	return Point(ccsprite->getScaleX(), ccsprite->getScaleY());
}

void FDSprite::setAnchorPoint(const Point& pos)
{
	ccsprite->setAnchorPoint(pos);
}

void FDSprite::setColor(int r, int g, int b)
{
	ccsprite->setColor(Color3B(r,g,b));
}

void FDSprite::setVisible(bool visible)
{
	ccsprite->setVisible(visible);
}

void FDSprite::setSprite(Sprite *s)
{
	ccsprite = s;
}

void FDSprite::setImage(FDImage *image, bool sizeChanged)
{
    Texture2D *texture = image->texture;
	ccsprite->setTexture(texture);
    
    if (sizeChanged) {
        Size texSize = texture->getContentSize();
        ccsprite->setTextureRect(Rect(0, 0, texSize.width, texSize.height));
    }
}

void FDSprite::setFrame(string fileName) {
    
    // NSString *fullName = [Common fileFullPath:fileName];
    // [UIImage imageNamed:fileName];
    
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(fileName);
    
    SpriteFrame *frame = cache->getSpriteFrameByName(fileName);
    ccsprite->setDisplayFrame(frame);
}


void FDSprite::addToLayer(Layer *layer)
{
	layer->addChild(ccsprite);
}

void FDSprite::removeFromLayer()
{
	ccsprite->removeFromParentAndCleanup(false);
}

FDSprite::~FDSprite()
{
	ccsprite->release();
}
