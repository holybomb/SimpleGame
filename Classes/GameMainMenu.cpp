#include "GameMainMenu.h"
#include "GameScene.h"

GameMainMenu::GameMainMenu(void)
{
}


GameMainMenu::~GameMainMenu(void)
{
}

cocos2d::CCScene* GameMainMenu::scene()
{
	CCScene* scene = CCScene::create();
	GameMainMenu* menuLayer = GameMainMenu::create();
	scene->addChild(menuLayer);
	return scene;
}

bool GameMainMenu::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	float w = winSize.width;
	float h = winSize.height;
	CCSprite* background = CCSprite::create("gamescene/background.png");
	background->setPosition(ccp(w/2,h/2));
	this->addChild(background);
	CCMenuItemFont* menu1 = CCMenuItemFont::create("开始游戏",this,menu_selector(GameMainMenu::menuStartCallback));

	CCMenuItemFont* menu2 = CCMenuItemFont::create("结束游戏",this,menu_selector(GameMainMenu::menuCloseCallback));


	CCMenu* menu = CCMenu::create(menu1,menu2,NULL);
	menu->setPosition(ccp(w/2,h/2));
    menu->alignItemsVertically();
	this->addChild(menu);
	return true;
}
void GameMainMenu::menuCloseCallback( CCObject* pSender )
{
    CCDirector::sharedDirector()->end();
	exit(0);
}
void GameMainMenu::menuStartCallback( CCObject* pSender )
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, GameScene::scene(), false));
}