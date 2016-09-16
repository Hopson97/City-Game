#include "Level.h"

#include "../Util/Window.h"

#include <iostream>

Level::Level( const std::string& name )
:   m_name      ( name )
,   m_builder   ( *this )
{
    m_background.setSize( { WIDTH, HEIGHT } );
    this->init();
}

void Level :: update( float dt)
{
    m_builder.input();

    m_values.update();

    for ( auto& building : m_buildings ) {

    }
    m_builder.update();
}

void Level :: draw()
{
    Window::draw( m_background );

    for ( auto& building : m_buildings ) {
        building->draw();
    }

    m_builder.draw();
    m_values.draw(); //aka the gui
}

void Level :: addBuilding ( std::shared_ptr<Building> b )
{
    m_values.m_resources -= b->m_data.cost;

    switch ( b->m_data.use )
    {
        case Building_Use::Housing:
            m_houses.push_back( b );
            break;

        default:
            break;
    }

    m_buildings.push_back( b );
}


const FloatRect_Vector& Level::getWaterSections() const
{
    return m_waterSections;
}

const FloatRect_Vector& Level::getGroundSections() const
{
    return m_groundSections;
}

const FloatRect_Vector& Level::getNoBuildSections() const
{
    return m_noBuildSections;
}
