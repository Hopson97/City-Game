#include "Mouse.h"

Mouse::Mouse()
{
    m_icon.loadFromFile( "Images/Cursor.png" );
    m_sprite.setTexture( m_icon );

    m_sprite.setOrigin( 5,5 );
}


void Mouse::update( const sf::RenderWindow& window )
{
    m_sprite.setPosition( sf::Mouse::getPosition( window ).x, sf::Mouse::getPosition( window ).y );
}


bool Mouse::isMouseDownLeft() const
{
    return sf::Mouse::isButtonPressed ( sf::Mouse::Left );
}


bool Mouse::isMouseDownRight() const
{
    return sf::Mouse::isButtonPressed ( sf::Mouse::Right );
}


const sf::Vector2f& Mouse::getPosition() const
{
    return m_sprite.getPosition();
}

void Mouse::draw( sf::RenderWindow& window )
{
    window.draw( m_sprite );
}
