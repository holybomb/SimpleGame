#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::CCLayer
{
public:

	CCTMXTiledMap* map;
	CCTMXObjectGroup* objLayer;
	CCTMXLayer* mapLayer;
	CCLabelTTF* label;
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    void registerWithTouchDispatcher();
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	CCPoint getMapPoint( CCPoint touchPoint );
};

#endif // __HELLOWORLD_SCENE_H__
