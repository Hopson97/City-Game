#ifndef BUILDING_TYPE_H
#define BUILDING_TYPE_H

#include "Building_Data.h"

struct Building
{
    Building( Building_Data& data, const sf::Vector2f& position );

    Building_Data& data; //This is basically a read only class (just constants) so it is fine to be public really

    const sf::Vector2f  position;
    const sf::FloatRect bounds;

    void draw();
};

#endif // BUILDING_TYPE_H
