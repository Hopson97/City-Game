#include "Symbolled_Update_Label.h"

#include "../Game.h"

#include "Window.h"

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
    m_label.setPosition ( m_thing.getPosition().x + xSize + 5, m_thing.getPosition().y );
    m_label.setString   ( std::to_string ( value ) );

    m_tooltip.setFont( Game::getFont( Font_Name::Rs ) );
    m_tooltip.setString( toolTip );

    m_label     .setCharacterSize( 15 );
    m_tooltip   .setCharacterSize( 15 );
}

void Symbolled_Update_Label :: update()
{

}

void Symbolled_Update_Label :: draw()
{
    Window::draw( m_thing );
    Window::draw( m_label );
}
