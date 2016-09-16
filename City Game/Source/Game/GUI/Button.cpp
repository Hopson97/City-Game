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
}

void Button :: checkForClick()
{
    if ( Mouse::isLeftDown() ) {
        m_function();
    }
}

void Button :: draw ()
{
    Window::draw( m_thing );
}

void Button :: onUpdate ()
{}
