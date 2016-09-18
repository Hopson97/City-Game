#ifndef BUILDING_TYPE_H
#define BUILDING_TYPE_H

#include <SFML/Graphics.hpp>
#include "Person_Group.h"

class Building_Data;



class Building
{
    public:
        Building( Building_Data& data, const sf::Vector2f& position );

        Building_Data& data; //This is basically a read only class (just constants) so it is fine to be public really

        const sf::Vector2f  position;
        const sf::FloatRect bounds;

        int getOccupantCount () const;

        void draw();

        bool isSpacesAvalibleToLive () const;
        bool isSpaceForWork         () const;

        void addPerson  ( PersonPtr person );
        void addWorker  ( PersonPtr person );

        Person_Group& destroy   ();

    private:
        Person_Group    m_people;
};

#endif // BUILDING_TYPE_H
