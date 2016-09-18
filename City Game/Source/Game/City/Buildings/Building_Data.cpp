#include "Building_Data.h"

#include <iostream>

#include "../../Util/Window.h"

#include "../../Game.h"

#include "../../Managers/Resource_Identifier.h"

namespace Builds
{
//Houses
struct Hut : public Building_Data
{
    Hut ()
    :   Building_Data ( "Hut",
                        Game::getTexture( Texture_Name::Building_Dwelling_Hut ) )
    {}
};

struct House : public Building_Data
{
    House ()
    :   Building_Data ( "House",
                        Game::getTexture( Texture_Name::Building_Dwelling_House ) )
    {}
};

//Wood
struct Woodcut_Hut : public Building_Data
{
    Woodcut_Hut ()
    :   Building_Data ( "Woodcutting Hut",
                        Game::getTexture( Texture_Name::Building_Wood_Woodcut_Hut ) )
    {}
};

//Stone
struct Small_Stone_Mine : public Building_Data
{
    Small_Stone_Mine ()
    :   Building_Data ( "Small Stone Mine",
                        Game::getTexture( Texture_Name::Building_Stone_Small_Mine ) )
    {}
};

}




Building_Data :: Building_Data ( Building_Use use,
                                 Resources    cost,
                                 Resources    rates,
                                 Statistics   change,
                                 const sf::Vector2f& size,
                                 const sf::Texture& texture )
:   m_use       ( use  )
,   m_cost      ( cost )
,   m_rates     ( rates )
,   m_stats     ( change )
,   m_sprite    ( size )
,   m_name      ( " " )
{
    m_sprite.setSize( size );
    m_sprite.setTexture( &texture );
}

Building_Data :: Building_Data( const std::string& strName,
                                const sf::Texture& texture )
:   m_name      ( strName )
{
    load ();
    m_sprite.setTexture( &texture );
}

Building_Use Building_Data :: getUse() const
{
    return m_use;
}

const Resources& Building_Data :: getCost() const
{
    return m_cost;
}

const Resources& Building_Data :: getRates() const
{
    return m_rates;
}

const Statistics& Building_Data :: getStats() const
{
    return m_stats;
}


const sf::Texture& Building_Data :: getTexture() const
{
    return *m_sprite.getTexture();
}

const sf::Vector2f& Building_Data :: getSize () const
{
    return m_sprite.getSize();
}

void Building_Data :: draw ( const sf::Vector2f& position )
{
    m_sprite.setPosition( position );
    Window::draw( m_sprite );
}



//Begin the database
class Building_Database
{
    public:
        Building_Database ()
        {
            m_database[ Building_Name::House_Hut ] = std::make_unique<Builds::Hut>();
            m_database[ Building_Name::House     ] = std::make_unique<Builds::House>();

            m_database[ Building_Name::Wood_Woodcut_Hut ] = std::make_unique<Builds::Woodcut_Hut>();

            m_database[ Building_Name::Stone_Small_Mine ] = std::make_unique<Builds::Small_Stone_Mine>();

        }

        std::map<Building_Name, std::unique_ptr<Building_Data>> m_database;
};

Building_Data& getBuildingData(Building_Name name)
{
    static Building_Database b;

    return *b.m_database.at( name );
}
















