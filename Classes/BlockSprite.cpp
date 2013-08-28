//
//  BlockSprite.cpp
//  SimpleGame
//
//  Created by 虎李 on 13-8-28.
//
//

#include "BlockSprite.h"
bool BlockSprite::init()
{
    if(!CCSprite::init())
    {
        return false;
    }
    return true;
}