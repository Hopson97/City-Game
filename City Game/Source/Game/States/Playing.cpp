#include "Playing.h"

#include <iostream>

namespace State
{

Playing::Playing( Game & game )
:	State_Base  ( game )
,   m_buildMenu ( BUILD_MENU_WIDTH, BUILD_MENU_HEIGHT, 0, BUILD_MENU_SEC_Y )
,   m_statsMenu ( 100, 185, Window::WIDTH - 100, 0 )
,   m_level     ( "River City" )
{
    Game::loadTexture( Res::getTexture( "Resource_Types/Gold" ),  Texture_Name::Resource_Coins  );
    Game::loadTexture( Res::getTexture( "Resource_Types/Logs" ),  Texture_Name::Resource_Logs   );
    Game::loadTexture( Res::getTexture( "Resource_Types/Stone" ), Texture_Name::Resource_Stones );
    Game::loadTexture( Res::getTexture( "Resource_Types/Metal" ), Texture_Name::Resource_Metal );
    Game::loadTexture( Res::getTexture( "Resource_Types/Food" ), Texture_Name::Resource_Food );

    m_buildMenu.setBgColour( { 100, 100, 100 } );
    m_statsMenu.setBgColour( { 100, 100, 100 } );

    setUpResourceGUI();

    m_game.changeSong( "euk" );

    Log::logMessage( "Switched to Playing state", Log_Type::State_Switch );
}



void Playing :: input( float dt )
{

}

void Playing :: update( float dt )
{
    m_buildMenu.update();
    m_statsMenu.update();
    m_level.update( dt );
}

void Playing :: draw( float dt )
{
    m_level.draw();

    m_buildMenu.draw();
    m_statsMenu.draw();
}


void Playing :: setBuildingMode( /* */ )
{

}

void Playing :: setUpResourceGUI()
{
    const int symbolSize = 32;
    int symbolY = 1;

    m_statsMenu.addSymbolUpdateLabel( Game::getTexture( Texture_Name::Resource_Coins),
                                     symbolSize, symbolSize,
                                     1, symbolY,
                                     m_resources.coins,
                                     "The amount of coins you have." );
    symbolY += symbolSize + 5;

    m_statsMenu.addSymbolUpdateLabel( Game::getTexture( Texture_Name::Resource_Logs),
                                     symbolSize, symbolSize,
                                     1, symbolY,
                                     m_resources.wood,
                                     "The amount of logs you have." );
    symbolY += symbolSize + 5;

    m_statsMenu.addSymbolUpdateLabel( Game::getTexture( Texture_Name::Resource_Stones),
                                     symbolSize, symbolSize,
                                     1, symbolY,
                                     m_resources.stone,
                                     "The amount of stone you have." );
    symbolY += symbolSize + 5;

    m_statsMenu.addSymbolUpdateLabel( Game::getTexture( Texture_Name::Resource_Metal),
                                     symbolSize, symbolSize,
                                     1, symbolY,
                                     m_resources.metal,
                                     "The amount of metal you have." );
    symbolY += symbolSize + 5;

    m_statsMenu.addSymbolUpdateLabel( Game::getTexture( Texture_Name::Resource_Food),
                                     symbolSize, symbolSize,
                                     1, symbolY,
                                     m_resources.food,
                                     "The amount of food you have." );
}



}
