#include "Button.h"

#include "Mouse.h"

Button :: Button(const sf::Texture t, int width, int height, int xPos, int yPos, std::function<void(void)>callback, const sf::Vector2f& guiPos )
:   m_function  ( callback )
{
    m_button.setSize    ( { (float)width, (float)height } );
    m_button.setPosition( xPos + guiPos.x, yPos + guiPos.y );
}

void Button :: checkForClick()
{
    if ( m_button.getGlobalBounds().contains( Mouse::getPosition() ) ) {
        if ( Mouse::isLeftDown() ) {
            m_function();
        }
    }
}
