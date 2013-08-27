#pragma once
#include "cocos2d.h"
#include <cstdio>
USING_NS_CC;
class GameMainMenu : public cocos2d::CCLayer
{
public:
	GameMainMenu(void);
	~GameMainMenu(void);
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();
	// a selector callback
	void menuCloseCallback(CCObject* pSender);
	// implement the "static node()" method manually
	CREATE_FUNC(GameMainMenu);
};

