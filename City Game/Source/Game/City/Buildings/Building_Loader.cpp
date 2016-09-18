#include "Building_Data.h"

#include <stdexcept>

namespace
{
    void loadResources ( Resources& resources, std::ifstream& inFile )
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
            else if ( identifier == "Unemp" ) {
                inFile >> resources.unemployedPopulation;
            }
            else if ( identifier == "END" ) {
                return;
            }
        }
    }

    void loadStats ( Statistics& statistics, Resources& resources, std::ifstream& inFile )
    {
        std::string identifier;

        while ( inFile >> identifier )
        {
            if ( identifier == "Population" ) {
                int val;
                inFile >> val;
                statistics.population = val;
                if ( resources.unemployedPopulation == 0 ) {
                    resources.unemployedPopulation = -val;
                }
            }
            else if ( identifier == "Vacancy" ) {
                inFile >> statistics.vacancy;
            }
            else if ( identifier == "Happiness" ) {
                inFile >> statistics.happiness;
            }
            else if ( identifier == "END" ) {
                return;
            }
        }
    }


} //Namespace anon


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
            loadStats( m_stats, m_cost, inFile );
        }
        else if ( identifier == "MISC" ) {
            loadMisc( inFile );
        }
    }
}
