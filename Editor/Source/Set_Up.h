#ifndef SET_UP_H_INCLUDED
#define SET_UP_H_INCLUDED

#include <SFML/Graphics.hpp>

bool validifyArgc( int argc );
bool validifyArgv( char** argv );

sf::Texture& getMapTexture();

#endif // SET_UP_H_INCLUDED
