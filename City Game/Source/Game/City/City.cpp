#include "City.h"

#include "../Util/Window.h"

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

void City :: update( float dt)
{
    if ( m_dayTimer.getElapsedTime() >= m_dayLength )
    {
        nextDay();
    }

    m_builder.input();

    m_values.update();

    for ( auto& building : m_buildings ) {

    }
    m_builder.update();

    m_newDayGUI.update();
    m_actionGUI.update();
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
    m_newDayGUI.draw();
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
    m_values.m_resources  -= b->data.getCost();
    m_values.m_statistics += b->data.getStats();

    m_values.m_dailyResourceChange += b->data.getRates();

    switch ( b->data.getUse() )
    {
        case Building_Use::Housing:
            m_houses.push_back( b );
            break;

        default:
            break;
    }

    m_buildings.push_back( b );
}

void City :: nextDay ()
{
    m_day++;
    m_dayTimer.restart();
    m_values.newDay( m_buildings );
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
