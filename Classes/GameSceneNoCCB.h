//
//  GameSceneNoCCB.h
//  SimpleGame
//
//  Created by 虎李 on 13-8-28.
//
//

#ifndef __SimpleGame__GameSceneNoCCB__
#define __SimpleGame__GameSceneNoCCB__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
class GameSceneNoCCB : public CCLayer{
public:
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(GameSceneNoCCB);
};
#endif /* defined(__SimpleGame__GameSceneNoCCB__) */
