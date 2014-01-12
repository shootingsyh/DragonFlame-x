//
//  FDImage.cpp
//  FlameDragon
//
//  Created by sui toney on 11-11-5.
//  Copyright 2011 ms. All rights reserved.
//

#import "FDImage.h"
#include "ObjectHelper.h"

USING_NS_CC;

bool FDImage::init(std::string fileName)
{
    Image image;
    image.initWithImageFile(fileName.c_str());
    texture = new Texture2D();
	texture->initWithImage(&image);
	return true;
}

bool FDImage::init(Texture2D *tex)
{
	texture = tex;
	return true;
}

FDImage::~FDImage() {
    texture->release();
}
