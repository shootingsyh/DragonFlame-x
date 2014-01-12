//
//  FDWindow.h
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/11/14.
//
//

#ifndef __PortedDragonFlame__FDWindow__
#define __PortedDragonFlame__FDWindow__

#include "cocos2d.h"

class FDWindow {
public:
    static const cocos2d::Size& getWinSize();

    static cocos2d::Point getScreenCenter();
    static cocos2d::Point getDownCenter();
    static cocos2d::Point getDownLeft();
    static cocos2d::Point getDownRight();
    static cocos2d::Point getUpCenter();

    static cocos2d::Point getShowBoxPosition();
    static cocos2d::Point getShowBoxDatoPosition();
    static cocos2d::Point getShowBoxDetailPosition();

    static cocos2d::Point getTitleButtonStart();
    static cocos2d::Point getTitleButtonLoad();
    static cocos2d::Point getTitleButtonContinue();

    static cocos2d::Point getVillageLocation(int position, int villageImageId);
    static cocos2d::Point getVillageLeftButton();
    static cocos2d::Point getVillageRightButton();
    static cocos2d::Point getSecretIndicatorPosition(int villageImageId);


    static cocos2d::Point getShowShoppingDialogPosition();
    static cocos2d::Point getChapterRecordShowLocation(int recordIndex);
    static cocos2d::Point getShoppingMessageLocation();
    static cocos2d::Point getShoppingMessageLocation2();
    static cocos2d::Point getVillageLabelLocation();

    static cocos2d::Point getFightingTaiPosition();
    static cocos2d::Point getFightingFriendBarPosition();
    static cocos2d::Point getFightingEnemyBarPosition();

    static cocos2d::Rect getLeftWindow();
    static cocos2d::Rect getRightWindow();

    static cocos2d::Point getMoneyBarLocation();
};

#endif /* defined(__PortedDragonFlame__FDWindow__) */
