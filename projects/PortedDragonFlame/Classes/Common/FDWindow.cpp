//
//  FDWindow.cpp
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/11/14.
//
//

#include "FDWindow.h"
USING_NS_CC;

const Size& FDWindow::getWinSize() {
    return Director::getInstance()->getWinSize();
}

Point FDWindow::getScreenCenter() {
	const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width / 2, winSize.height / 2);
}

Point FDWindow::getDownCenter() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width / 2, winSize.height / 4);
}
Point FDWindow::getDownLeft() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width / 4, winSize.height / 4);
}
Point FDWindow::getDownRight() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width / 1.3, winSize.height / 4);
}
Point FDWindow::getUpCenter() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width / 2, winSize.height / 1.3);
}

Point FDWindow::getShowBoxPosition() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width / 2, winSize.height * 0.28);
}
Point FDWindow::getShowBoxDatoPosition() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width * 0.15, winSize.height * 0.72);
}
Point FDWindow::getShowBoxDetailPosition() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width * 0.64, winSize.height * 0.72);
}

Point FDWindow::getTitleButtonStart() {
    const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width * 0.2, winSize.height * 0.13);
}
Point FDWindow::getTitleButtonLoad() {
	const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width * 0.5, winSize.height * 0.13);
}
Point FDWindow::getTitleButtonContinue() {
	const Size& winSize = FDWindow::getWinSize();
	return Point(winSize.width * 0.8, winSize.height * 0.13);
}

Point FDWindow::getVillageLocation(int position, int villageImageId) {
	const Size& winSize = FDWindow::getWinSize();
	
	switch (villageImageId) {
		case 1:
			switch (position) {
				case 0:
					return Point(winSize.width * 0.24, winSize.height * 0.10);
				case 1:
					return Point(winSize.width * 0.52, winSize.height * 0.25);
				case 2:
					return Point(winSize.width * 0.6, winSize.height * 0.58);
				case 3:
					return Point(winSize.width * 0.15, winSize.height * 0.7);
				case 4:
					return Point(winSize.width * 0.2, winSize.height * 0.4);
				case 5:
					return Point(winSize.width * 0.08, winSize.height * 0.85);
				default:
					return Point(0, 0);
			}
			break;
		case 2:
			switch (position) {
				case 0:
					return Point(winSize.width * 0.24, winSize.height * 0.10);
				case 1:
					return Point(winSize.width * 0.55, winSize.height * 0.25);
				case 2:
					return Point(winSize.width * 0.8, winSize.height * 0.75);
				case 3:
					return Point(winSize.width * 0.25, winSize.height * 0.77);
				case 4:
					return Point(winSize.width * 0.2, winSize.height * 0.27);
				case 5:
					return Point(winSize.width * 0.5, winSize.height * 0.85);
				default:
					return Point(0, 0);
			}
		case 3:
			switch (position) {
				case 0:
					return Point(winSize.width * 0.24, winSize.height * 0.10);
				case 1:
					return Point(winSize.width * 0.52, winSize.height * 0.25);
				case 2:
					return Point(winSize.width * 0.76, winSize.height * 0.55);
				case 3:
					return Point(winSize.width * 0.35, winSize.height * 0.75);
				case 4:
					return Point(winSize.width * 0.2, winSize.height * 0.4);
				case 5:
					return Point(winSize.width * 0.68, winSize.height * 0.85);
				default:
					return Point(0, 0);
			}
			break;
		default:
			break;
	}
	
	return Point(0, 0);
}
Point FDWindow::getVillageLeftButton() {
	return Point(40, 40);
}
Point FDWindow::getVillageRightButton() {
	return Point(FDWindow::getWinSize().width - 40, 40);
}
Point FDWindow::getSecretIndicatorPosition(int villageImageId) {
	switch (villageImageId) {
		case 1:
			return Point(12.5, 193);
		case 2:
			return Point(287.5, 81.5);
		case 3:
            return Point(108, 115);
        default:
    		break;
	}
	
	return Point(0, 0);
}


Point FDWindow::getShowShoppingDialogPosition() {
	return Point(0, 0);
}
Point FDWindow::getChapterRecordShowLocation(int recordIndex) {
	return Point(FDWindow::getWinSize().width * 0.3, 62 - recordIndex * 18);
}
Point FDWindow::getShoppingMessageLocation() {
	return Point(20, 60);
}
Point FDWindow::getShoppingMessageLocation2() {
	return Point(20, 35);
}
Point FDWindow::getVillageLabelLocation() {
	return Point(FDWindow::getWinSize().width * 0.9, FDWindow::getWinSize().height * 0.1);
}

Point FDWindow::getFightingTaiPosition() {
	return Point(FDWindow::getWinSize().width * 0.7, FDWindow::getWinSize().height * 0.2);
}
Point FDWindow::getFightingFriendBarPosition() {
	return Point(FDWindow::getWinSize().width * 0.7, FDWindow::getWinSize().height * 0.85);
}
Point FDWindow::getFightingEnemyBarPosition() {
	return Point(FDWindow::getWinSize().width * 0.25, FDWindow::getWinSize().height * 0.1);
}

Rect FDWindow::getLeftWindow() {
	return Rect(0, 0, FDWindow::getWinSize().width / 2, FDWindow::getWinSize().height);
}
Rect FDWindow::getRightWindow() {
	return Rect(FDWindow::getWinSize().width / 2, 0, FDWindow::getWinSize().width, FDWindow::getWinSize().height);
}

Point FDWindow::getMoneyBarLocation() {
	return Point(8, 145);
}