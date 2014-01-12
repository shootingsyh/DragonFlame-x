//
//  Common.h
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/11/14.
//
//

#ifndef __PortedDragonFlame__Common__
#define __PortedDragonFlame__Common__

#include "cocos2d.h"


class Common: public cocos2d::Object {
public:
    std::string toString(int val, int digit);
    std::string getDocumentDir();
    std::string getFileFullPath(std::string fileName);

    bool containInt(int num, cocos2d::Array* arr);

};
#endif /* defined(__PortedDragonFlame__Common__) */
