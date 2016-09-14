#include "Mouse.h"

#include "Window.h"

namespace
{
    sf::Sprite  m_sprite;
    sf::Texture m_icon;
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
    m_sprite.setPosition( sf::Mouse::getPosition( Window::get() ).x, sf::Mouse::getPosition( Window::get() ).y );
}


bool isLeftDown()
{
    return sf::Mouse::isButtonPressed ( sf::Mouse::Left );
}


bool isRightDown()
{
    return sf::Mouse::isButtonPressed ( sf::Mouse::Right );
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
