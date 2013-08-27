//
//  MainMenu.h
//  SimpleGame
//
//  Created by 虎李 on 13-8-27.
//
//

#ifndef __SimpleGame__MainMenu__
#define __SimpleGame__MainMenu__

#include <iostream>
#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;
class MainMenu : public CCLayer,public CCBSelectorResolver,public CCBMemberVariableAssigner{
    
public:
    void onPressButton(CCObject* pSender);
    CREATE_FUNC(MainMenu);
   ~MainMenu()
	{
	    CC_SAFE_RELEASE_NULL( m_TestLabel );
	}
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
private:
    CCLabelTTF* m_TestLabel;
};

class MainMenuLoader : public CCLayerLoader{
public:

	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( MainMenuLoader, loader );
	
	CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( MainMenu );
};

#endif /* defined(__SimpleGame__MainMenu__) */
