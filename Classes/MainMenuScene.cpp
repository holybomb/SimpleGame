//
//  MainMenuScene.cpp
//  SimpleGame
//
//  Created by 虎李 on 13-8-27.
//
//

#include "MainMenuScene.h"
CCScene* MainMenuScene::scene()
{
    CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader( "MainMenu", MainMenuLoader::loader());
    CCBReader* reader = new CCBReader( CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary() );
    reader->autorelease();
    return reader->createSceneWithNodeGraphFromFile( "MainScene.ccbi" ) ;
}