#include "Button.h"

#include "../Util/Mouse.h"
#include "../Util/Window.h"

Button:: Button (    const sf::Vector2f& size,
                     const sf::Vector2f& position,
                     const sf::Vector2f& guiPos,
                     const sf::Texture&  texture,
                     std::function<void(void)> callback
                )
:   GUI_Feature ( size, position, guiPos, texture )
,   m_function ( callback )
{
    auto fp = std::bind(&Button::checkForClick, this);
    addRollOverFunction ( fp );
    //addRollOverFunction ( std::bind ( Button::checkForClick, this ) );
}

void Button :: checkForClick()
{
    if ( m_isActive ) {
        if ( Mouse::isLeftDown() ) {
            m_function();
            m_activeTimer.restart();
        }
    }

    return;
}

void Button :: draw ()
{
    Window::draw( m_thing );
}

void Button :: onUpdate ()
{
    if ( m_activeTimer.getElapsedTime().asSeconds() >= 0.2 ) {
        m_isActive = true;
    }
    else  {
        m_isActive = false;
    }
}
