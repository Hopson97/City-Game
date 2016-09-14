#include "Symbolled_Update_Label.h"

#include "../Game.h"

#include "Window.h"

#include <iostream>

Symbolled_Update_Label :: Symbolled_Update_Label(   int xSize,
                                                    int ySize,
                                                    int xPos,
                                                    int yPos,
                                                    const sf::Vector2f& guiOffset,
                                                    const sf::Texture& m_symbol,
                                                    const int& value,
                                                    const std::string& toolTip )
:   GUI_Feature ( xSize, ySize, xPos, yPos, guiOffset, m_symbol )
,   m_valueI    ( &value )
{
    m_label  .setFont   ( Game::getFont( Font_Name::Rs ) );
    m_label  .setPosition ( m_thing.getPosition().x + xSize + 5, m_thing.getPosition().y );

    onUpdate();

    m_tooltip.setFont( Game::getFont( Font_Name::Rs ) );
    m_tooltip.setString( toolTip );
    m_tooltip.setPosition( 25, 25 );

    m_label     .setCharacterSize( 15 );
    m_tooltip   .setCharacterSize( 15 );

    addRollOverFunction( std::bind ( Symbolled_Update_Label::drawToolTip, this ) );
}

void Symbolled_Update_Label :: onUpdate()
{
    m_label.setString   ( std::to_string ( *m_valueI ) );

    if ( m_toolTipTimer.getElapsedTime().asSeconds() >= 0.01 ) {
            m_isToolTipActive = false;
    }
}

void Symbolled_Update_Label :: draw()
{
    Window::draw( m_thing );
    Window::draw( m_label );

    if ( m_isToolTipActive ) {
        Window::draw( m_tooltip );
    }
}

void Symbolled_Update_Label :: drawToolTip()
{
    m_isToolTipActive = true;
    m_toolTipTimer.restart();
}
