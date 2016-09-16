#include "Mouse.h"

#include "Window.h"

#include <iostream>

namespace
{
    sf::Sprite  m_sprite;
    sf::Texture m_icon;

    bool m_isActive = false;
    sf::Clock m_activeTimer;

    bool isButtonDown ( bool b )
    {
        if ( m_isActive ) {
            if ( b ) {
                m_activeTimer.restart();
                return true;
            }
        }
        return false;
    }
}

namespace Mouse
{

void init()
{
    m_icon.loadFromFile( "Data/Textures/Cursor.png" );
    m_sprite.setTexture( m_icon );
    m_sprite.setOrigin( 5,5 );
}


void update( )
{
    m_sprite.setPosition( sf::Mouse::getPosition( Window::get() ).x,
                          sf::Mouse::getPosition( Window::get() ).y );

    if ( m_activeTimer.getElapsedTime().asSeconds() >= 0.2 ) {
        m_isActive = true;
    }
    else  {
        m_isActive = false;
    }
}


bool isLeftDown()
{
    return isButtonDown( sf::Mouse::isButtonPressed ( sf::Mouse::Left ) );
}


bool isRightDown()
{
    return isButtonDown( sf::Mouse::isButtonPressed ( sf::Mouse::Right ) );
}


const sf::Vector2f& getPosition()
{
    return m_sprite.getPosition();
}

void draw()
{
    Window::draw( m_sprite );
}

}
