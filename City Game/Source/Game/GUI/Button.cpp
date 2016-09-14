#include "Button.h"

#include "Mouse.h"
#include "Window.h"

Button :: Button(const sf::Texture& t, int width, int height, int xPos, int yPos, std::function<void(void)>callback, const sf::Vector2f& guiPos )
:   GUI_Feature ( width, height, xPos, yPos, guiPos, t )
,   m_function  ( callback )
{
    addRollOverFunction ( std::bind ( Button::checkForClick, this ) );
}

void Button :: checkForClick()
{
    if ( m_isActive ) {
        if ( Mouse::isLeftDown() ) {
            m_function();
            m_activeTimer.restart();
        }
    }
}

void Button :: draw ()
{
    Window::draw( m_thing );
}

void Button :: onUpdate ()
{
    if ( m_activeTimer.getElapsedTime().asSeconds() >= 0.2 ) {
        m_isActive = true;
    } else {
        m_isActive = false;
    }
}
