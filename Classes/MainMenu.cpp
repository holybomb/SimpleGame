//
//  MainMenu.cpp
//  SimpleGame
//
//  Created by 虎李 on 13-8-27.
//
//

#include "MainMenu.h"
#include "GameMainMenu.h"

void MainMenu::onPressButton(CCObject* pSender)
{
    CCDirector::sharedDirector()->pushScene(CCTransitionFadeUp::create(1, GameMainMenu::scene()));
}
cocos2d::SEL_MenuHandler MainMenu::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
   CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(pTarget, "onPressButton", MainMenu::onPressButton);
   return NULL;
}
cocos2d::extension::SEL_CCControlHandler MainMenu::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(pTarget, pSelectorName, MainMenu::onPressButton);
    return NULL;
}
bool MainMenu::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
	m_TestLabel = NULL;
    CCB_MEMBERVARIABLEASSIGNER_GLUE(pTarget, pMemberVariableName, CCLabelTTF*, m_TestLabel);
    return false;
}