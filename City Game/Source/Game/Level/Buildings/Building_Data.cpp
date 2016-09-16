#include "Building_Data.h"

#include "../../Util/Window.h"

Building_Data :: Building_Data ( Building_Use use,
                                 Resources cost,
                                 Resources rates,
                                 const sf::Vector2f& size,
                                 const sf::Texture& texture )
:   use     ( use  )
,   cost    ( cost )
,   rates   ( rates )
,   m_sprite    ( size )
{
    m_sprite.setTexture( &texture );
}


void Building_Data :: draw ( const sf::Vector2f& position )
{
    Window::draw( m_sprite );
}
