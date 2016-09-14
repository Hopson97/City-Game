#include "App.h"

#include <fstream>
#include <iostream>
#include <string>
#include <iostream>

//For now, this is only for OFFCIAL maps, as I will hard code the maps into the actual game for now

bool numSaved = false;

namespace
{
    void saveRect ( std::ofstream& saveFile, const sf::FloatRect& rect )
    {
        saveFile << rect.left << " " << rect.top << " " << rect.width << " " << rect.height << std::endl;
    }
}

void App :: save ()
{
    static int num = 0;
    if ( !numSaved )
    {
            std::ifstream inFile ( "Maps/info.dat");
            inFile >> num;
            num++;
            inFile.close();
            std::ofstream outFile ( "Maps/info.dat");
            outFile << num;

    }


    std::cout << "Saving as " << num << ".cgm\". Change the number in this file to change the name of the map + add a description (lines 1 and 2)" << std::endl;

    std::ofstream saveFile ( "Maps/" + std::to_string ( num ) + ".cgm" );
    saveFile << num << std::endl << num << std::endl;
    mapImage.saveToFile( "Images/SavedMaps/" + std::to_string(num) + ".png" );

    for ( auto& rect : m_collisionRects )
    {
        saveFile << "c ";
        saveRect( saveFile, rect.getGlobalBounds() );
    }
    for ( auto& rect : m_waterRects )
    {
        saveFile << "w ";
        saveRect( saveFile, rect.getGlobalBounds() );
    }
    for ( auto& rect : m_groundRects )
    {
        saveFile << "g ";
        saveRect( saveFile, rect.getGlobalBounds() );
    }
}

