#include "Button.h"

#include "Mouse.h"
#include "Window.h"

Button :: Button(const sf::Texture& t, int width, int height, int xPos, int yPos, std::function<void(void)>callback, const sf::Vector2f& guiPos )
:   GUI_Feature ( width, height, xPos, yPos, guiPos, t )
,   m_function  ( callback )
{ }

void Button :: checkForClick()
{
    if ( m_thing.getGlobalBounds().contains( Mouse::getPosition() ) ) {
        if ( Mouse::isLeftDown() ) {
            m_function();
        }
    }
}

void Button :: draw ()
{
    Window::draw( m_thing );
}

void Button :: update ()
{
    checkForClick();
}
