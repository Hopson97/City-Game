#ifndef BUILDING_TYPE_H
#define BUILDING_TYPE_H

#include <SFML/Graphics.hpp>

class Building_Data;
class Person;

class Building
{
    public:
        Building( Building_Data& data, const sf::Vector2f& position );

        Building_Data& data; //This is basically a read only class (just constants) so it is fine to be public really

        const sf::Vector2f  position;
        const sf::FloatRect bounds;

        int getOccupantCount () const;

        void draw();

    private:
        std::vector<Person*> m_occupants; //Is a vector of pointers, but not to dynamic memory so dw about memory leaks tbh
};

#endif // BUILDING_TYPE_H
