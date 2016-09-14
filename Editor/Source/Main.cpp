#include <SFML/Graphics.hpp>
#include <iostream>

#include "Set_Up.h"

#include "App.h"


int main( int argc, char** argv )
{
    if ( validifyArgc( argc ) ) {
        if ( !validifyArgv( argv ) )
            return -1;
    }
    else
    {
        std::string def = "Images/Maps/test.png";
        argv[1] = (char*)def.c_str();
    }

    std::cout << "Load successful!" << std::endl;

    App app ( argv[1]);
    app.run();

}
