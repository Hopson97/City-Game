#include "City.h"

#include "../Util/Window.h"

#include <iostream>

City::City( const std::string& name )
:   m_name      ( name )
,   m_builder   ( *this, m_values )
{
    m_background.setSize( { WIDTH, HEIGHT } );
    this->init();
}

void City :: update( float dt)
{
    if ( m_dayTimer.getElapsedTime() >= m_dayLength )
    {
        m_dayTimer.restart();
        m_values.newDay();
    }

    m_builder.input();

    m_values.update();

    for ( auto& building : m_buildings ) {

    }
    m_builder.update();
}

void City :: draw()
{
    Window::draw( m_background );

    for ( auto& building : m_buildings ) {
        building->draw();
    }

    m_builder.draw();
    m_values.draw(); //aka the gui
}

void City :: tryAddBuilding ( std::shared_ptr<Building> b )
{
    //Make sure it is actually being added within the bounds of the map
    if ( !b->bounds.intersects( m_background.getGlobalBounds() ) ) return;

    //If all the checks have passed, it will add the buildings
    addBuilding( b );
}

void City :: addBuilding(std::shared_ptr<Building>b)
{
    //Deduct/ Increase the player's resource values
    m_values.m_resources  -= b->data.cost;
    m_values.m_statistics += b->data.change;

    m_values.m_dailyResourceChange += b->data.rates;

    switch ( b->data.use )
    {
        case Building_Use::Housing:
            m_houses.push_back( b );
            break;

        default:
            break;
    }

    m_buildings.push_back( b );
}



const FloatRect_Vector& City :: getWaterSections() const
{
    return m_waterSections;
}

const FloatRect_Vector& City :: getGroundSections() const
{
    return m_groundSections;
}

const FloatRect_Vector& City::getNoBuildSections() const
{
    return m_noBuildSections;
}

const Building_Ptr_Vector& City :: getBuildings () const
{
    return m_buildings;
}
