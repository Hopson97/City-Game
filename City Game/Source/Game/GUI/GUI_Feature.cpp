#include "GUI_Feature.h"

#include "../Util/Mouse.h"

GUI_Feature :: GUI_Feature (    const sf::Vector2f& size,
                                const sf::Vector2f& position,
                                const sf::Vector2f& guiPos,
                                const sf::Texture&  texture )
{
    m_thing.setSize     ( size );
    m_thing.setPosition ( position.x + guiPos.x, position.y + guiPos.y );
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
