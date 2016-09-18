#include "City.h"

#include <iostream>
#include <cassert>

#include "../Util/Window.h"
#include "../Util/Random.h"

#include "../Game.h"


City::City( const std::string& name )
:   m_name      ( name )
,   m_builder   ( *this, m_values )
,   m_actionGUI ( { Window::WIDTH / 8, Builder::BUILD_MENU_HEIGHT}, { Window::WIDTH - Window::WIDTH / 8, Builder::BUILD_MENU_SEC_Y } )
,   m_newDayGUI ( { Window::WIDTH / 6, 100 }, {  Window::WIDTH / 2 - Window::WIDTH / 6, 25 } )
{
    m_background.setSize( { WIDTH, HEIGHT } );
    this->init();

    m_actionGUI.setBgColour( { 50, 50, 50 } );

    m_actionGUI.beginColumn( {10, 0 }, 5 );

    m_actionGUI.addSymbolUpdateLabel( { 20, 20 },
                                      Game::getTexture( Texture_Name::Days),
                                      m_day,
                                      "Number of days passed" );

    m_actionGUI.addButton ( {50, 20 },
                            Game::getTexture( Texture_Name::GUI_Next_Day_Button ),
                            std::bind ( &City::nextDay, this ) );

    m_actionGUI.setTitle( "Actions" );
}

void City::removeBuilding( Building& b )
{
    //Re add the resources and then get the group of people of whom were evicted
    m_values.m_resources += b.data.getCost() / 4;

    Person_Group group = b.destroy();
    m_values.m_statistics.homeless += group.occupants.size();

    m_values.m_statistics.vacancy += group.occupants.size();

    m_values.m_statistics -= b.data.getStats();
    group.clear();
}

void City::tryDestory(sf::FloatRect area)
{
    for ( size_t i = 0 ; i < m_buildings.size() ; i++ )
    {
        Building& b = *m_buildings.at( i );
        if ( b.bounds.intersects ( area ) ) {
            b.destroy();
            removeBuilding( b );
            m_buildings.erase( m_buildings.begin() + i );
        }
    }
}



void City :: update( float dt)
{
    m_builder.input();

    m_values.update();

    m_builder.update();

    m_newDayGUI.update();
    m_actionGUI.update();

    if ( m_dayTimer.getElapsedTime() >= m_dayLength ) {
        nextDay();
    }
}

void City :: draw()
{
    Window::draw( m_background );

    for ( auto& building : m_buildings ) {
        building->draw();
    }

    m_builder.draw();
    m_values.draw(); //aka the gui

    m_actionGUI.draw();
    //m_newDayGUI.draw();
}

void City :: tryAddBuilding ( std::shared_ptr<Building> b )
{
    //Make sure it is actually being added within the bounds of the map
    if ( !b->bounds.intersects( m_background.getGlobalBounds() ) ) return;

    //If all the checks have passed, it will add the buildings
    addBuilding( b );
}

void City :: addBuilding( std::shared_ptr<Building>b )
{
    //Deduct/ Increase the player's resource values
    m_values.m_resources  -= b->data.getCost();
    m_values.m_statistics += b->data.getStats();

    switch ( b->data.getUse() )
    {
        case Building_Use::Housing:
            m_houses.push_back( b );
            break;

        case Building_Use::Work:
            m_workPlaces.push_back( b );
            break;
    }

    m_buildings.push_back( b );
}

void City :: nextDay ()
{
    m_day++;
    m_dayTimer.restart();
    m_values.newDay( m_buildings );

    tryGetMoveIns();
    tryAddWorkers();
    m_values.m_statistics.population = m_people.size();
}

void City::tryGetMoveIns()
{
    //Add new people into the city if there are vacancies
    int people = Random::integer( 0, m_day + 5 );
    if ( people > m_values.m_statistics.vacancy ) people = m_values.m_statistics.vacancy;
    m_values.m_statistics.vacancy -= people;

    for ( int i = 0 ; i < people ; i++ ) {
        addPerson ();
    }

    m_values.m_statistics.population = m_people.size();
}

void City::tryAddWorkers()
{
    for ( auto& person : m_people )
    {
        if ( person->isUnemployed() ) {
            int workPlace = Random::integer( 0, m_workPlaces.size() - 1 ) ;
            Building& b = *m_workPlaces.at( workPlace );

            if ( b.isSpaceForWork() ) {
                b.addWorker( person );

                m_values.m_statistics.unemployedPopulation--;
                m_values.m_statistics.jobs--;

                person->setWork ( b );
            }
        }
    }
}


void City :: addPerson ()
{
    for ( auto& house : m_houses ) {
        if ( house->isSpacesAvalibleToLive() ) {
            PersonPtr p = std::make_shared<Person>();
            m_people.push_back( p );
            house->addPerson ( p );
            p->setHouse ( *house );
            m_values.m_statistics.unemployedPopulation++;
            break;
        }
    }
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
