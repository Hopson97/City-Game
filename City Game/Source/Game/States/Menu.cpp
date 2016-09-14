#include "Menu.h"

#include <iostream>

namespace State
{

Menu::Menu( Game & game )
:	State_Base ( game )
{
    m_game.changeSong( "euk" );

    Log::logMessage( "Switched to Menu state", Log_Type::State_Switch );
}

void Menu::input( float dt )
{

}

void Menu::update( float dt )
{

}

void Menu::draw( float dt )
{
}

}
