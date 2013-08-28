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
//    CCScene* scene =CCScene::create();
//    GameScene* gameScene = (GameScene*)reader->readNodeGraphFromFile("GameScene.ccbi");
//    if(gameScene!=NULL)
//    {
//        CCSprite* sprite = gameScene->getSpriteFromFile();
//        if(sprite!=NULL)
//        {
////            gameScene->addChild(sprite);
//            sprite->setPosition(ccp(100, 200));
//        }
//        scene->addChild(sprite);
//    }
//    return scene;
    return reader->createSceneWithNodeGraphFromFile("GameScene.ccbi");
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
        CCSprite* block = CCSprite::create("0.png");
        block->setPosition(ccp(10,10));
        CCLOG("block add : size is %fx%f",block->getContentSize().width,block->getContentSize().height);
        this->addChild(block);
    }
}
