//
//  TitleScene.cpp
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/4/14.
//
//

#include "TitleScene.h"
#include "TitleLayer.h"
#include "ObjectHelper.h"

bool TitleScene::init() {
	TitleLayer* mainLayer = ::create<TitleLayer>();
	
	addChild(mainLayer);
	
	return true;
}
