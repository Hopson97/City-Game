#include "Building.h"

#include "Building_Data.h"

Building :: Building ( Building_Data& data, const sf::Vector2f& position )
:   data      ( data )
,   position  ( position )
,   bounds    ( position, data.getSize() )
{ }

void Building :: draw ()
{
    data.draw ( position );
}
