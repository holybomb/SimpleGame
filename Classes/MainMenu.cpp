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
	//if (pTarget == pTarget && 0 == strcmp(pMemberVariableName, (pMemberVariableName))) { 
	//	CCLabelTTF* pOldVar = m_TestLabel; 
	//	m_TestLabel = dynamic_cast<CCLabelTTF*>(pNode); 
	//	CC_ASSERT(m_TestLabel); 
	//	if (pOldVar != m_TestLabel) { 
	//		//CC_SAFE_RELEASE(pOldVar); 
	//		do 	
	//		{ 
	//			if(pOldVar) 
	//			{ 
	//				(pOldVar)->release(); 
	//			} 
	//		} while(0);
	//		m_TestLabel->retain(); 
	//	} 
	//	return true; 
	//}
    return false;
}