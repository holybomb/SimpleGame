//
//  GameScene.cpp
//  SimpleGame
//
//  Created by 虎李 on 13-8-28.
//
//

#include "GameScene.h"
#include "BlockSprite.h"
CCScene* GameScene::scene()
{
    CCNodeLoaderLibrary* lib = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    CCNodeLoader* loader = GameSceneLoader::loader();
    lib->registerCCNodeLoader( "GameScene",loader);
    CCBReader* reader = new CCBReader( lib );
    reader->autorelease();
    CCNode* node = reader->readNodeGraphFromFile("GameScene.ccbi");
    CCScene* scene =CCScene::create();
    if(node!=NULL)
    {
        scene->addChild(node);
    }
    return scene;
//    return reader->createSceneWithNodeGraphFromFile("GameScene.ccbi");
}
bool GameScene::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    setTouchEnabled(true);
//    addChild(node);
    return true;
}
GameScene::GameScene()
:mGameLayer(NULL)
{
}
bool GameScene::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget,const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(pTarget, "gameLayer", CCLayer*, mGameLayer);
    return false;
}
CCSprite* GameScene::getSpriteFromFile()
{
    CCNodeLoaderLibrary* lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader* reader = new CCBReader(lib);
    CCSprite* sprite = (CCSprite* )reader->readNodeGraphFromFile("block.ccbi");
    return sprite;
}
void GameScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    CCLOG("onNodeLoaded");
    if(mGameLayer!=NULL)
    {
        CCSize winSize = mGameLayer->getContentSize();
        float x = mGameLayer->getPositionX();
        float y = mGameLayer->getPositionY();
        float w = winSize.width;
        float h = winSize.height;
        float offX = w/GAME_LAYER_SIZE_W;
        float offY = h/GAME_LAYER_SIZE_H;
        mGameLayer->removeAllChildren();
        for(int i =0;i<GAME_LAYER_SIZE_H;i++)
        {
            for (int j =0; j<GAME_LAYER_SIZE_W; j++) {
                CCSprite* sprite = getSpriteFromFile();
                int sw = sprite->getContentSize().width;
                int sh = sprite->getContentSize().height;
                sprite->setPosition(ccp(x+sw+offX*j,y+sh+offY*i));
                CCLOG("block %d is add",j+GAME_LAYER_SIZE_W*i);
                mGameLayer->addChild(sprite,0,j+GAME_LAYER_SIZE_W*i);
            }
        }

    }
}
void GameScene::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-10,true);
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    for(int i =0;i<mGameLayer->getChildrenCount();i++)
    {
        CCNode* block = mGameLayer->getChildByTag(i);
        if (block==NULL) {
            CCLOG("block %d is null",i);
            continue;
        }
        CCPoint winPoint = mGameLayer->convertToNodeSpace(block->getPosition());
        CCRect blockRc = CCRectMake(winPoint.x,winPoint.y, block->getContentSize().width, block->getContentSize().height);
        CCPoint touchPoint = mGameLayer->convertTouchToNodeSpace(pTouch);
//        CCRect blockRc = CC_RECT_POINTS_TO_PIXELS(block->getPosition());
        if(blockRc.containsPoint(touchPoint))
        {
            block->setVisible(false);
        }
    }
    return true;
}
