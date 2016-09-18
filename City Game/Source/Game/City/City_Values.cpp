#include "City_Values.h"

#include <iostream>

#include "../Util/Window.h"

#include "../Game.h"

#include "../Managers/Resource_Identifier.h"

#include "Buildings/Building_Data.h"

constexpr static int EXPLOIT_MODE = 9'999'999;

City_Values::City_Values()
:   m_resources     ( 200, 25, 25, 25, 25 )
//:   m_resources     ( EXPLOIT_MODE, EXPLOIT_MODE, EXPLOIT_MODE, EXPLOIT_MODE, EXPLOIT_MODE )
,   m_resourceGUI   ( { 100, 34 * 6 }, {Window::WIDTH - 100, 0} )
,   m_statsGUI      ( { 100, 34 * 7 }, {0,0 } )
{
    m_resourceGUI   .setBgColour    ( { 100, 100, 100 } );
    m_statsGUI      .setBgColour    ( { 100, 100, 100 } );

    m_statistics.happiness = 50;

    m_resourceGUI   .setResizeable( true );
    m_statsGUI      .setResizeable( true );

    setUpResourceGUI();
    setUpStatisticGUI();
}

void City_Values :: update()
{
    m_resourceGUI   .update();
    m_statsGUI      .update();
}

void City_Values :: draw()
{
    m_resourceGUI   .draw();
    m_statsGUI      .draw();
}

void City_Values :: newDay( const std::vector<std::shared_ptr<Building>>& buildings )
{
    //We have to take the rates away individually, just in case there are not enough resources to take away.
    for ( const auto& building : buildings )
    {
        int occupants = building->getOccupantCount();
        if ( occupants == 0 ) {
            continue;
        }

        for ( int i = 0 ; i < occupants ; i++ ) {
            tryDoRates  ( m_resources.coins,   building->data.getRates().coins );
            tryDoRates  ( m_resources.food,    building->data.getRates().food );
        }
        tryDoRates  ( m_resources.metal,   building->data.getRates().metal );
        tryDoRates  ( m_resources.stone,   building->data.getRates().stone );
        tryDoRates  ( m_resources.wood,    building->data.getRates().wood );
    }
    m_statistics.happiness -= m_statistics.homeless / 2;
}

void City_Values :: tryDoRates (int& rate, int amount)
{

    if ( rate + amount >= 0 ) {
        rate += amount;
    } else {
        m_statistics.happiness--;
    }
}

const int padding = 6;

void City_Values :: setUpResourceGUI()
{
    const sf::Vector2f symbolSize ( 32, 32 );
    m_resourceGUI.beginColumn( { padding, 1 }, padding );

    m_resourceGUI.setTitle( "Resources" );

    m_resourceGUI.addSymbolUpdateLabel( symbolSize,
                                        Game::getTexture( Texture_Name::Resource_Coins),
                                        m_resources.coins,
                                        "The amount of coins you have." );

    m_resourceGUI.addSymbolUpdateLabel( symbolSize,
                                        Game::getTexture( Texture_Name::Resource_Logs),
                                        m_resources.wood,
                                        "The amount of logs you have." );

    m_resourceGUI.addSymbolUpdateLabel( symbolSize,
                                        Game::getTexture( Texture_Name::Resource_Stones),
                                        m_resources.stone,
                                        "The amount of stone you have." );

    m_resourceGUI.addSymbolUpdateLabel( symbolSize,
                                        Game::getTexture( Texture_Name::Resource_Metal),
                                        m_resources.metal,
                                        "The amount of metal you have." );

    m_resourceGUI.addSymbolUpdateLabel( symbolSize,
                                        Game::getTexture( Texture_Name::Resource_Food),
                                        m_resources.food,
                                        "The amount of food you have." );
}


void City_Values::setUpStatisticGUI()
{
    const sf::Vector2f symbolSize ( 32, 32 );
    m_statsGUI.beginColumn( { padding, 1 }, padding );

    m_statsGUI.setTitle( "Statistics" );


    m_statsGUI.addSymbolUpdateLabel( symbolSize,
                                     Game::getTexture( Texture_Name::Stat_Population),
                                     m_statistics.population,
                                     "Population living in your city." );


    m_statsGUI.addSymbolUpdateLabel( symbolSize,
                                     Game::getTexture( Texture_Name::Stat_Vacancy),
                                     m_statistics.vacancy,
                                     "Vacant housing  spaces in your city." );

    m_statsGUI.addSymbolUpdateLabel( symbolSize,
                                     Game::getTexture( Texture_Name::Stat_Happiness),
                                     m_statistics.happiness,
                                     "The overall happiness of your people." );

    m_statsGUI.addSymbolUpdateLabel( symbolSize,
                                     Game::getTexture( Texture_Name::Stat_Unemployed),
                                     m_statistics.unemployedPopulation,
                                     "Unemployed people looking for work." );

    m_statsGUI.addSymbolUpdateLabel( symbolSize,
                                     Game::getTexture( Texture_Name::Stat_Jobs),
                                     m_statistics.jobs,
                                     "Jobs that are open for workers." );

    m_statsGUI.addSymbolUpdateLabel( symbolSize,
                                     Game::getTexture( Texture_Name::Stat_Homeless),
                                     m_statistics.homeless,
                                     "Homeless people living in your city." );
}
