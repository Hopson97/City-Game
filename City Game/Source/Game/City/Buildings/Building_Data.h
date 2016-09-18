#ifndef BUILDING_DATA_H
#define BUILDING_DATA_H

#include <fstream>

#include "E_Building_Use.h"
#include "../City_Values.h"

enum Building_Name
{
    House_Hut,
    House,

    Wood_Woodcut_Hut,

    Stone_Small_Mine,

    Metal_Ore_Refinery,

    Food_Farm
};


class Building_Data
{
    public:
        Building_Data ( const std::string& strName,
                        const sf::Texture& texture );

        Building_Use getUse () const;

        const Resources&     getCost   ()  const;   //How much this building costs to build
        const Resources&     getRates  ()  const;   //How much this building influences the player's rate daily
        const Statistics&    getStats  ()  const;

        const sf::Texture&  getTexture  () const;
        const sf::Vector2f& getSize     () const;

        void draw ( const sf::Vector2f& position );

    private:
        void load ();
        void loadResources  ( Resources& resources, std::ifstream& inFile );
        void loadStats      ( std::ifstream& inFile );
        void loadMisc       ( std::ifstream& inFile );

        Building_Use  m_use;

        Resources     m_cost;   //How much this building costs to build
        Resources     m_rates;  //How much this building influences the player's rate daily
        Statistics    m_stats;

        std::string m_description;

        sf::RectangleShape m_sprite;

        const std::string m_name;

        int m_maxOccupants;
};


Building_Data& getBuildingData(Building_Name name);



#endif // BUILDING_DATA_H
