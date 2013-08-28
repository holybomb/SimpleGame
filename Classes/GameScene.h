//
//  GameScene.h
//  SimpleGame
//
//  Created by 虎李 on 13-8-28.
//
//

#ifndef __SimpleGame__GameScene__
#define __SimpleGame__GameScene__

#include <iostream>

#include <iostream>
#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define GAME_LAYER_SIZE_W 5
#define GAME_LAYER_SIZE_H 5
class GameScene : public CCLayer,public CCBMemberVariableAssigner,public CCNodeLoaderListener{
private:
    CCLayer* mGameLayer;
public:
    GameScene();
    ~GameScene()
    {
        CC_SAFE_RELEASE_NULL(mGameLayer);
    }
    static CCScene* scene();
    void genBlockLayer();
    CCSprite* getSpriteFromFile();
    CREATE_FUNC(GameScene);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
};

class GameSceneLoader : public CCLayerLoader{
public:
    
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( GameSceneLoader, loader );
	
	CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( GameScene );
};

#endif /* defined(__SimpleGame__GameScene__) */
