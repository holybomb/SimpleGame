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
CCSprite* GameScene::getSpriteFromFile(const char* fileName)
{
    CCNodeLoaderLibrary* lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader* reader = new CCBReader(lib);
    CCSprite* sprite = (CCSprite* )reader->readNodeGraphFromFile(fileName);
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
//        blockMap = CCTMXTiledMap::create("hexa-test.tmx");
//        blockMap->setPosition(ccp(x, y));
//        blockMap->setScale(0.5f);
//        mGameLayer->addChild(blockMap);
        CCSprite* spriteBg = CCSprite::create("blocktiles.png");
        float offX = spriteBg->getContentSize().width+spriteBg->getContentSize().width/2;//w/GAME_LAYER_SIZE_W;
        float offY = spriteBg->getContentSize().height/2;//h/GAME_LAYER_SIZE_H;
        int mapW = (w+offX)/offX;
        int mapH = (h-offY)/offY;
        spriteBg->release();
//        mGameLayer->removeAllChildren();
        if(mapH%2==0)
            mapH = mapH-1;
        for(int i =0;i<mapH;i++)
        {
            int maxW = mapW-(i%2==0?0:1);
            for (int j =0; j<maxW; j++) {
                CCSprite* spriteBg = getSpriteFromFile("blockBG.ccbi");
                spriteBg->setAnchorPoint(ccp(0.0f, 0.0f));
                
                int start = 0;
                int end = 5;
                int index = CCRANDOM_0_1()*end+start;
                CCString* file = CCString::createWithFormat("block%i.ccbi",index);
                CCSprite* sprite = getSpriteFromFile(file->getCString());// CCSprite::create(file->getCString());
                sprite->setAnchorPoint(ccp(0.5f, 0.5f));
                int sw = spriteBg->getContentSize().width;
                int sh = spriteBg->getContentSize().height;
                
//                CCLOG("block %d is add",j+mapW*i);
                if(i%2!=0)
                {
                    spriteBg->setPosition(ccp(offX*j+offX/2, offY*i));
                    sprite->setPosition(ccp(offX*j+offX/2+sw/2,offY*i+sh/2));
                }
                else
                {
                    spriteBg->setPosition(ccp(offX*j, offY*i));
                    sprite->setPosition(ccp(offX*j+sw/2,offY*i+sh/2));
                }
                mGameLayer->addChild(spriteBg,0,j+maxW*i);
                mGameLayer->addChild(sprite,1,(j+maxW*i)*(mapW*mapW));
            }
        }
//
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
