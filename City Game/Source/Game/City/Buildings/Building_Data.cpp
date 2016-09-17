#include "Building_Data.h"

#include <iostream>

#include "../../Util/Window.h"

#include "../../Game.h"

#include "../../Managers/Resource_Identifier.h"

namespace House_Data
{
    struct Hut : public Building_Data
    {
        Hut()
        :   Building_Data   ( Building_Use::Housing,
                            { 20, 2, 0, 0, 1 }, //The cost
                            { 1, 0, 0, 0, -1  }, //The rates aka how much resources does this structure increase
                            { 2, 0, 2, -1    }, //Statistic change
                            { 16, 16         }, //The size (pixel size on the window)
                            Game::getTexture( Texture_Name::Building_Dwelling_Hut ) )
        { }
    };

    struct House : public Building_Data
    {
        House()
        :   Building_Data   ( Building_Use::Housing,
                            { 50, 5, 5, 2, 5 }, //The cost
                            { 5, 0, 0, 0, -6 }, //The rates aka how much resources does this structure increase
                            { 5, 0, 5, 1     }, //Statistic change
                            { 25, 25         }, //The size (pixel size on the window)
                            Game::getTexture( Texture_Name::Building_Dwelling_House ) )
        { }
    };
}

Building_Data :: Building_Data ( Building_Use use,
                                 Resources    cost,
                                 Resources    rates,
                                 Statistics   change,
                                 const sf::Vector2f& size,
                                 const sf::Texture& texture )
:   use         ( use  )
,   cost        ( cost )
,   rates       ( rates )
,   change      ( change )
,   m_sprite    ( size )
{
    m_sprite.setSize( size );
    m_sprite.setTexture( &texture );
}


void Building_Data :: draw ( const sf::Vector2f& position )
{
    m_sprite.setPosition( position );
    Window::draw( m_sprite );
}

const sf::Texture& Building_Data :: getTexture() const
{
    return *m_sprite.getTexture();
}

const sf::Vector2f& Building_Data :: getSize () const
{
    return m_sprite.getSize();
}

//Begin the database
class Building_Database
{
    public:
        Building_Database ()
        {
            m_database[ Building_Name::House_Hut ] = std::make_unique<House_Data::Hut>();
            m_database[ Building_Name::House     ] = std::make_unique<House_Data::House>();
        }

        std::map<Building_Name, std::unique_ptr<Building_Data>> m_database;
};

Building_Data& getBuildingData(Building_Name name)
{
    static Building_Database b;

    return *b.m_database.at( name );
}
















