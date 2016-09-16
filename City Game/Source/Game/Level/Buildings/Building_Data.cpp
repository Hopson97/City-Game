#include "Building_Data.h"

#include <iostream>

#include "../../Util/Window.h"

#include "../../Game.h"

#include "../../Managers/Resource_Identifier.h"

namespace House_Data
{
    struct Base_House_Data : public Building_Data
    {
        Base_House_Data(  int maxOccupants,
                          Resources cost,
                          Resources rates,
                          const sf::Vector2f& size,
                          const sf::Texture& texture )
        : Building_Data ( Building_Use::Housing,
                          cost,
                          rates,
                          size,
                          texture )
        , maxOccupants  ( maxOccupants )
        {}

        const int maxOccupants;
    };

    struct Hut : public Base_House_Data
    {
        Hut()
        :   Base_House_Data ( 2,                //Maximum Occupants
                            { 20, 2, 0, 0, 1 }, //The cost
                            { 1, 0, 0, 0, 0 },  //The rates
                            { 16, 16 },         //The size (pixel size on the window)
                            Game::getTexture( Texture_Name::Building_Dwelling_Hut ) )
        { }

    };
}

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
        }

        std::map<Building_Name, std::unique_ptr<Building_Data>> m_database;
};

Building_Data& getBuildingData(Building_Name name)
{
    static Building_Database b;

    return *b.m_database.at( name );
}
















