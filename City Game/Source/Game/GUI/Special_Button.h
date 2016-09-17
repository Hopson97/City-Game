#ifndef SPECIAL_BUTTON_H
#define SPECIAL_BUTTON_H

#include <functional>

#include "GUI_Feature.h"
#include "../Util/Mouse.h"
#include "../Util/Window.h"

template <typename Function_Arg>
class Special_Button : public GUI_Feature
{
    public:
        Special_Button ( const sf::Vector2f& size,
                         const sf::Vector2f& position,
                         const sf::Vector2f& guiPos,
                         const sf::Texture&  texture,
                         std::function<void(Function_Arg* )> callback,
                         Function_Arg& arg )
        :   GUI_Feature ( size, position, guiPos, texture )
        ,   m_function ( callback )
        {
            auto fp = std::bind(&Special_Button::checkForClick, this);
            addRollOverFunction ( fp );
        }

        void draw       () override
        {
            Window::draw( m_thing );
        }

        void onUpdate   () override
        { }

    private:
        void checkForClick()
        {
            if ( Mouse::isLeftDown() ) {
                m_function( m_functionArg );
            }
        }

        std::function<void(Function_Arg*)> m_function;
        Function_Arg* m_functionArg;
};

#endif // SPECIAL_BUTTON_H
