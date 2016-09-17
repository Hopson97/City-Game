#ifndef BUILDING_DATA_H
#define BUILDING_DATA_H

#include "E_Building_Use.h"
#include "../City_Values.h"

enum Building_Name
{
    House_Hut,
    House,

    Wood_Woodcut_Hut,

    Stone_Small_Mine
};

struct Building_Data
{
    Building_Data( Building_Use use,
                   Resources    cost,
                   Resources    rates,
                   Statistics   change,
                   const sf::Vector2f& size,
                   const sf::Texture& texture );

    const Building_Use  use;
    const Resources     cost;   //How much this building costs to build
    const Resources     rates;  //How much this building influences the player's rate daily
    const Statistics    change;

    const sf::Texture&  getTexture  () const;
    const sf::Vector2f& getSize     () const;

    void draw ( const sf::Vector2f& position );

    private:
        sf::RectangleShape m_sprite;
};

Building_Data& getBuildingData(Building_Name name);


#endif // BUILDING_DATA_H
