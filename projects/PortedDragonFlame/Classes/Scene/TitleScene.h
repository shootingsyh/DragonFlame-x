//
//  TitleScene.h
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/4/14.
//
//

#ifndef PortedDragonFlame_TitleScene_h
#define PortedDragonFlame_TitleScene_h

#include "cocos2d.h"

class TitleLayer;
class TitleScene : public cocos2d::Scene {
public:
    virtual bool init();

private:
	TitleLayer *mainLayer;
};
#endif