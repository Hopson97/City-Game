#include "Playing.h"

#include <iostream>

namespace State
{

Playing::Playing( Game & game )
:	State_Base ( game )
,   m_buildMenu ( MENU_WIDTH, MENU_HEIGHT, 0, MENU_SEC_Y )
,   m_level     ( "River City" )
{
    Game::loadTexture( Res::getTexture( "GUI/Bricks" ),   Texture_Name::GUI_Brick,  false );

    m_buildMenu.setBgColour( { 100, 100, 100, 255 } );

    //m_buildMenu.addButton   ( Game::getTexture( Texture_Name::TEMP2 ), 20, 20, 10, 10, std::bind( &Playing::testButton, this ) );

    m_game.changeSong( "euk" );

    Log::logMessage( "Switched to Playing state", Log_Type::State_Switch );
}

void Playing :: input( float dt )
{

}

void Playing :: update( float dt )
{
    m_buildMenu.update();
    m_level.update( dt );
}

void Playing :: draw( float dt )
{
    m_level.draw();

    m_buildMenu.draw();
}


void Playing :: setBuildingMode( /* */ )
{

}

}
