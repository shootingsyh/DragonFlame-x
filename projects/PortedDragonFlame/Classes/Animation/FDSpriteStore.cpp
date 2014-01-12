//
//  FDSpriteStore.m
//  FlameDragon
//
//  Created by sui toney on 11-11-3.
//  Copyright 2011 ms. All rights reserved.
//

#include "FDSpriteStore.h"
#include "ObjectHelper.h"
USING_NS_CC;

FDSpriteStore::FDSpriteStore() {
	spriteDictionary = Dictionary::create();
    imageDictionary = Dictionary::create();
    spriteDictionary->retain();
    imageDictionary->retain();
}

FDSpriteStore::~FDSpriteStore() {
    spriteDictionary->release();
    imageDictionary->release();
}

FDSpriteStore* FDSpriteStore::instance = nullptr;

FDSpriteStore* FDSpriteStore::getInstance()
{
    if(FDSpriteStore::instance == nullptr)
	{
		instance = new FDSpriteStore();
	}
	return instance;
}

FDImage* FDSpriteStore::getImage(std::string fileName)
{
	if (imageDictionary->objectForKey(fileName) == nullptr)
	{
		FDImage* image = create<FDImage>(fileName);
		imageDictionary->setObject(image, fileName);
	}
	
	return dynamic_cast<FDImage*>(imageDictionary->objectForKey(fileName));
}


FDSprite * FDSpriteStore::getSprite(std::string fileName)
{
	FDSprite *sprite = create<FDSprite>(fileName);
	
	return sprite;
	
	/*
	NSString *identi = [NSString stringWithFormat:@"%@_%d", fileName, i];
	
	if ([spriteDictionary objectForKey:identi] == nil)
	{
		FDSprite *sprite = [[FDSprite alloc] initFromFile:fileName];
		[spriteDictionary setObject:sprite forKey:identi];
		[sprite release];
	}
	
	return [spriteDictionary objectForKey:identi];
	 */
}
