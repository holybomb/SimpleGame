#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
int kTagTileMap = 0;;


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
	this->setTouchEnabled(true);
    map = CCTMXTiledMap::create("tmw_desert_spacing.tmx");
	addChild(map,0,kTagTileMap);
	objLayer = map->objectGroupNamed("objLayer");
	mapLayer = map->layerNamed("mapLayer");
	label = CCLabelTTF::create("Hello world","",25.0f);
	label->setColor(ccc3(23,55,33));
	addChild(label,0,10);
	label->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height-label->getContentSize().height));
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

bool HelloWorld::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	//CCPoint point = map->convertToNodeSpace(pTouch->getLocation());
	//int x = point.x;
	//int y = point.y;
	//CCString* str = CCString::createWithFormat("Touch in x:%d , y:%d",x,y);
	////label = this->getChildByTag(10);
	//label->setString(str->getCString());
	CCPoint touchPoint = pTouch->getLocation();
	CCPoint mapPoint = this->getMapPoint(touchPoint);
	int gid = mapLayer->tileGIDAt(mapPoint);
	CCString* str = CCString::createWithFormat("GID:%d \nTouch in x:%d , y:%d",gid,(int)mapPoint.x,(int)mapPoint.y);
	////label = this->getChildByTag(10
	CCDictionary* dic = map->propertiesForGID(gid);
	if(dic)
	{
		int isPlant = ((CCString*)dic->objectForKey("isPlant"))->intValue();
		CCLOG("isPlant=%d",isPlant);
	}
	label->setString(str->getCString());
	/*ccDrawColor4B(255,0,0,255);
	ccPointSize(64);
	ccDrawPoint(CCDirector::sharedDirector()->convertToUI(touchPoint));*/
	return true;
}

void HelloWorld::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-1,true);
}

cocos2d::CCPoint HelloWorld::getMapPoint( CCPoint touchPoint )
{
	float x = touchPoint.x/map->getTileSize().width;
	float y = ((map->getMapSize().height)*(map->getTileSize().height)-touchPoint.y)/map->getTileSize().height;
	CCLOG("%d,%d",(int)x,(int)y);
	return ccp(x,y);
}
