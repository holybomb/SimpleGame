//
//  GameSceneNoCCB.cpp
//  SimpleGame
//
//  Created by 虎李 on 13-8-28.
//
//

#include "GameSceneNoCCB.h"
bool GameSceneNoCCB::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	float w = winSize.width;
	float h = winSize.height;
	CCSprite* background = CCSprite::create("gamescene/background.png");
	background->setPosition(ccp(w/2,h/2));
    addChild(background);
    CCSprite* sprite = CCSprite::create("CloseNormal.png");
    sprite->setPosition(ccp(w/2,h/2));
    addChild(sprite);
    return true;
}
CCScene* GameSceneNoCCB::scene()
{
    CCScene* scene = CCScene::create();
    GameSceneNoCCB* layer = GameSceneNoCCB::create();
    scene->addChild(layer);
    return scene;
}