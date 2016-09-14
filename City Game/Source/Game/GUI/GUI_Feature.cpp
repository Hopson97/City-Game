#include "GUI_Feature.h"

GUI_Feature::GUI_Feature(int xSize, int ySize, int xPos, int yPos, const sf::Vector2f& guiOffset, const sf::Texture& texture )
{
    m_thing.setSize     ( { (float)xSize, (float)ySize } );
    m_thing.setPosition ( xPos + guiOffset.x, yPos + guiOffset.y );
    m_thing.setTexture  ( &texture );
}

