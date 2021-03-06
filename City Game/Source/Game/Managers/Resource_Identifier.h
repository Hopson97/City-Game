#ifndef RESOURCE_IDENTIFIER_H_INCLUDED
#define RESOURCE_IDENTIFIER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Resource_Manager.h"

namespace Res
{
    inline std::string getTexture( const std::string& name )
    {
        return "Data/Textures/" + name + ".png";
    }


    inline std::string getSound( const std::string& name )
    {
        return "Data/Sounds/" + name + ".ogg";
    }


    inline std::string getFont( const std::string& name )
    {
        return "Data/Fonts/" + name + ".ttf";
    }
}

enum class Font_Name
{
	Arial,
	Rs
};

enum class Sound_Name
{
    Example
};

enum class Texture_Name
{
    SFML_Logo,

    Active_Map,

    GUI_Brick,
    GUI_Resize_Button,
    GUI_Destroy_Mode_Button,

    GUI_Next_Day_Button,

    Days,

    Resource_Coins,
    Resource_Logs,
    Resource_Stones,
    Resource_Metal,
    Resource_Food,

    Stat_Population,
    Stat_Unemployed,
    Stat_Vacancy,
    Stat_Happiness,
    Stat_Jobs,
    Stat_Homeless,

    Building_Dwelling_Hut,
    Building_Dwelling_House,

    Building_Wood_Woodcut_Hut,

    Building_Stone_Small_Mine,

    Building_Metal_Ore_Refinery,

    Building_Food_Farm,

    TEMP2
};

typedef Resource_Manager<Font_Name,     sf::Font>           Font_Manager;
typedef Resource_Manager<Sound_Name,    sf::SoundBuffer>    Sound_Manager;
typedef Resource_Manager<Texture_Name,  sf::Texture>        Texture_Manager;






#endif // RESOURCE_IDENTIFIER_H_INCLUDED
