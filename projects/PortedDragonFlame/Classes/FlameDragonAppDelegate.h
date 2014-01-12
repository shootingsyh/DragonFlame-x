#ifndef  _FLAME_DRAGON_APP_DELEGATE_H_
#define  _FLAME_DRAGON_APP_DELEGATE_H_

//
//  FlameDragonAppDelegate.h
//  FlameDragon
//
//  Created by yonghong shi on 2014-01-04.
//  Copyright ms 2014. All rights reserved.
//

#include "cocos2d.h"
class  FlameDragonAppDelegate : private cocos2d::Application
{
public:
    FlameDragonAppDelegate() {};
    virtual ~FlameDragonAppDelegate() {};
    
    /**
     @brief    Implement Director and Scene init code here.
     @return true    Initialize success, app continue.
     @return false   Initialize failed, app terminate.
     */
    virtual bool applicationDidFinishLaunching();
    
    /**
     @brief  The function be called when the application enter background
     @param  the pointer of the application
     */
    virtual void applicationDidEnterBackground();
    
    /**
     @brief  The function be called when the application enter foreground
     @param  the pointer of the application
     */
    virtual void applicationWillEnterForeground();
};
#endif