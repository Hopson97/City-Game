#include "GUI_Feature.h"

#include "Mouse.h"

GUI_Feature::GUI_Feature(int xSize, int ySize, int xPos, int yPos, const sf::Vector2f& guiOffset, const sf::Texture& texture )
{
    m_thing.setSize     ( { (float)xSize, (float)ySize } );
    m_thing.setPosition ( xPos + guiOffset.x, yPos + guiOffset.y );
    m_thing.setTexture  ( &texture );
}

void GUI_Feature :: addRollOverFunction ( std::function<void(void)> f )
{
    m_rollOverfunction = f;
    m_hasRollOverFunction = true;
}

void GUI_Feature :: update()
{
    onUpdate();

    if ( m_thing.getGlobalBounds().contains( Mouse::getPosition() ) && m_hasRollOverFunction ) {
        m_rollOverfunction();
    }
}
