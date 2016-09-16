#include "Building.h"

Building :: Building ( Building_Data& data, const sf::Vector2f& position )
:   m_data      ( data )
,   m_position  ( position )
{ }

void Building :: draw ()
{
    m_data.draw ( m_position );
}
