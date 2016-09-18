#include "Building_Data.h"

#include <stdexcept>


void Building_Data :: loadResources ( Resources& resources, std::ifstream& inFile )
{
    std::string identifier;

    while ( inFile >> identifier )
    {
        if ( identifier == "Coins" ) {
            inFile >> resources.coins;
        }
        else if ( identifier == "Wood" ) {
            inFile >> resources.wood;
        }
        else if ( identifier == "Stone" ) {
            inFile >> resources.stone;
        }
        else if ( identifier == "Metal" ) {
            inFile >> resources.metal;
        }
        else if ( identifier == "Food" ) {
            inFile >> resources.food;
        }
        //else if ( identifier == "Unemp" ) {
        //    inFile >> resources.unemployedPopulation;
        //}
        else if ( identifier == "END" ) {
            return;
        }
    }
}

void Building_Data :: loadStats ( std::ifstream& inFile )
{
    std::string identifier;

    while ( inFile >> identifier )
    {
        if ( identifier == "Vacancy" ) {
            inFile >> m_stats.vacancy;
            m_maxOccupants += m_stats.vacancy;
        }
        else if ( identifier == "Happiness" ) {
            inFile >> m_stats.happiness;
        }
        else if ( identifier == "Jobs" ) {
            inFile >> m_stats.jobs;
            m_maxOccupants += m_stats.jobs;
        }
        else if ( identifier == "END" ) {
            return;
        }
    }
}


void Building_Data :: loadMisc ( std::ifstream& inFile )
{
        std::string identifier;
        while ( inFile >> identifier )
        {
            if ( identifier == "Size" ) {
                float x, y;
                inFile >> x >> y;
                m_sprite.setSize( { x, y } );
            }
            else if ( identifier == "Use" ) {
                int use;
                inFile >> use;
                m_use = static_cast<Building_Use>( use );
            }
            else if ( identifier == "Description" ) {
                std::getline( inFile, m_description, '\n' );
            }
            else if ( identifier == "END" ) {
                return;
            }
        }
}

void Building_Data :: load ()
{
    std::ifstream inFile( "Data/Buildings/" + m_name + ".build" );

    if ( !inFile.is_open() ) {
        throw std::runtime_error ( "Missing file data for " + m_name + "." );
    }

    std::string identifier;
    while ( inFile >> identifier ) {
        if ( identifier == "COST" ) {
            loadResources( m_cost, inFile );
        }
        else if ( identifier == "RATES" ) {
            loadResources( m_rates, inFile );
        }
        else if ( identifier == "STATS" ) {
            loadStats( inFile );
        }
        else if ( identifier == "MISC" ) {
            loadMisc( inFile );
        }
    }
}
