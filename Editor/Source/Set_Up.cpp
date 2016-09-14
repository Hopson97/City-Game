#include "Set_Up.h"

#include <iostream>
#include <memory>

namespace
{
    sf::Texture mapTexture;

    void loadDefault()
    {
        mapTexture.loadFromFile( "Images/Maps/test.png");
        std::cin.ignore();
    }
}

bool validifyArgc( int argc )
{
    if ( argc == 1 ) {
        std::cout << "No map file input, loading default map. Press enter to continue" << std::endl;
        loadDefault();
        return false;
    } else {
        return true;
    }
}

bool validifyArgv( char** argv )
{
    if ( !mapTexture.loadFromFile( argv[1] ) ) {
        std::cout << "Not able to open file! Loading default map. Press enter to close." << std::endl;
        loadDefault();
        return false;
    }
    return true;
}

sf::Texture& getMapTexture()
{
    return mapTexture;
}
