//
//  BlockSprite.h
//  SimpleGame
//
//  Created by 虎李 on 13-8-28.
//
//

#ifndef __SimpleGame__BlockSprite__
#define __SimpleGame__BlockSprite__

#include <iostream>
#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;
class BlockSprite : public CCSprite {
public:
    bool init();
    CREATE_FUNC(BlockSprite);
};
#endif /* defined(__SimpleGame__BlockSprite__) */
