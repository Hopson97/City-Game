#include "Playing.h"

#include <iostream>

namespace State
{

Playing::Playing( Game & game )
:	State_Base      ( game )
,   m_buildMenu     ( {BUILD_MENU_WIDTH, BUILD_MENU_HEIGHT}, {0, BUILD_MENU_SEC_Y} )
{
    Game::loadTexture( Res::getTexture( "Resource_Types/Gold" ),  Texture_Name::Resource_Coins  );
    Game::loadTexture( Res::getTexture( "Resource_Types/Logs" ),  Texture_Name::Resource_Logs   );
    Game::loadTexture( Res::getTexture( "Resource_Types/Stone" ), Texture_Name::Resource_Stones );
    Game::loadTexture( Res::getTexture( "Resource_Types/Metal" ), Texture_Name::Resource_Metal );
    Game::loadTexture( Res::getTexture( "Resource_Types/Food" ), Texture_Name::Resource_Food );

    Game::loadTexture( Res::getTexture( "Statistics/Population"), Texture_Name::Stat_Population );
    Game::loadTexture( Res::getTexture( "Statistics/Vacancy" ), Texture_Name::Stat_Vacancy );

    m_buildMenu     .setBgColour    ( { 100, 100, 100 } );

    m_level = std::make_unique<Level>( "River City" );

    Log::logMessage( "Switched to Playing state", Log_Type::State_Switch );
}

void Playing :: input( float dt )
{

}

void Playing :: update( float dt )
{
    m_buildMenu     .update();
    m_level        ->update( dt );
}

void Playing :: draw( float dt )
{
    m_level    ->draw();
    m_buildMenu .draw();
}


void Playing :: setBuildingMode( /* */ )
{

}

}
