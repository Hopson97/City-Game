#include "Level.h"

#include <fstream>
#include <iostream>

#include "../Managers/Resource_Identifier.h"

#include "../Game.h"


/*
    This function loads up the map files created from the map editor. This includes stuff like where you
    are able to build certain things, water sections and non-build zones.

    It also loads up the image for the background of the level, too.
*/
void Level :: init()
{
    std::string m_backgroundTexture = Res::getTexture( "Maps/" + m_name );
    std::string mapFilePath         = "Data/Maps/" + m_name + ".cgm";

    Game::loadTexture( m_backgroundTexture, Texture_Name::Active_Map, true );
    m_background.setTexture( &Game::getTexture( Texture_Name::Active_Map) );

    std::ifstream inFile ( mapFilePath );
    if ( !inFile.is_open() ) {
        throw std::runtime_error ( "Unable to open the map file for " + m_name );
    } else {
        char identifier;
        while ( inFile >> identifier ) {
            if ( identifier == 'c' ) {
                loadFloatRectToVector( m_noBuildSections,   inFile );
            }
            else if ( identifier == 'g' ) {
                loadFloatRectToVector( m_groundSections,    inFile );
            }
            else if ( identifier == 'w' ) {
                loadFloatRectToVector( m_waterSections,     inFile );
            }
        }
    }
}

void Level :: loadFloatRectToVector ( std::vector<sf::FloatRect>& vect, std::ifstream& inFile )
{
    float left, top, width, height;
    inFile >> left >> top >> width >> height;
    vect.emplace_back( left, top, width, height );
}
