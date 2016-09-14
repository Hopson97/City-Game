#include "Splash_Screen.h"

#include <iostream>
#include "Menu.h"
#include "Playing.h"
#include "../Managers/Resource_Identifier.h"

namespace State
{

Splash_Screen :: Splash_Screen ( Game& game )
:   State_Base ( game )
{
    m_game.loadTexture  ( Res::getTexture   ( "sfml" ),     Texture_Name::SFML_Logo );
    m_game.loadFont     ( Res::getFont      ( "arial" ),    Font_Name::Arial        );
    m_game.loadSound    ( Res::getSound     ( "example" ),  Sound_Name::Example     );

    m_splashes.push_back( Splash{ m_game.getTexture ( Texture_Name::SFML_Logo),
                                  m_game.getSound ( Sound_Name::Example ),
                                  3 } );
    m_splashes.back().addText( m_game.getFont( Font_Name::Arial ), "Made using: " );

    Log::logMessage( "Switched to Splash Screen state", Log_Type::State_Switch );
}

void Splash_Screen :: input ( float dt )
{}

void Splash_Screen:: update ( float dt )
{
    if ( !m_splashes.empty() ) {
        m_splashes.at( 0 ).update();

        if ( m_splashes.at( 0 ).hasFinished() ) {
            m_splashes.erase( m_splashes.begin() );
        }
    }

    if ( m_splashes.empty() ) m_game.changeState( std::make_unique <State::Playing> ( m_game ) );
}

void Splash_Screen:: draw ( float dt )
{}

Splash_Screen :: Splash :: Splash ( const sf::Texture& texture, const sf::SoundBuffer& sound, float seconds, bool stretch )
:   m_time      ( seconds )
,   m_hasSound  ( true )
{
    setUp( texture, stretch );

    m_sound.setBuffer( sound );
}


Splash_Screen :: Splash :: Splash(const sf::Texture& texture, float seconds, bool stretch )
:   m_time      ( seconds )
,   m_hasSound  ( false )
{
    setUp( texture, stretch );
}



void Splash_Screen :: Splash :: setUp ( const sf::Texture& texture, bool stretch )
{
    m_sprite.setTexture ( &texture );

    if ( stretch ) {
        m_sprite.setSize ( { Window::WIDTH, Window::HEIGHT } );
    }
    else {
        float width = texture.getSize().x;
        float height = texture.getSize().y;

        m_sprite.setSize ( { width, height } );

        m_sprite.setPosition ( Window::WIDTH / 2  - width  / 2,
                               Window::HEIGHT / 2 - height / 2 );
    }
}




void Splash_Screen :: Splash :: update()
{
    if  ( !m_hasBegun ) {
        m_timer.restart();
        m_hasBegun = true;
        if ( m_hasSound ) m_sound.play();
    }

    Window::draw( m_sprite );
    Window::draw( m_text );
}

bool Splash_Screen :: Splash :: hasFinished()
{
    return m_timer.getElapsedTime().asSeconds() >= m_time;
}

void Splash_Screen :: Splash :: addText ( const sf::Font& font, const std::string& text )
{
    m_text.setFont( font );
    m_text.setString( text );
    m_text.setCharacterSize( 20 );
}



}
