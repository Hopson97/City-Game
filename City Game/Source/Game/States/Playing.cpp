#include "Playing.h"

#include <iostream>

namespace State
{

Playing::Playing( Game & game )
:	State_Base      ( game )
{
    Game::loadTexture( Res::getTexture( "Resource_Types/Gold"   ),  Texture_Name::Resource_Coins    );
    Game::loadTexture( Res::getTexture( "Resource_Types/Logs"   ),  Texture_Name::Resource_Logs     );
    Game::loadTexture( Res::getTexture( "Resource_Types/Stone"  ),  Texture_Name::Resource_Stones   );
    Game::loadTexture( Res::getTexture( "Resource_Types/Metal"  ),  Texture_Name::Resource_Metal    );
    Game::loadTexture( Res::getTexture( "Resource_Types/Food"   ),  Texture_Name::Resource_Food     );

    Game::loadTexture( Res::getTexture( "Statistics/Population" ),  Texture_Name::Stat_Population   );
    Game::loadTexture( Res::getTexture( "Statistics/Unemployed" ),  Texture_Name::Stat_Unemployed   );
    Game::loadTexture( Res::getTexture( "Statistics/Vacancy"    ),  Texture_Name::Stat_Vacancy      );
    Game::loadTexture( Res::getTexture( "Statistics/Happiness"  ),  Texture_Name::Stat_Happiness    );

    Game::loadTexture( Res::getTexture( "Buildings/Dwellings/Hut"       ),  Texture_Name::Building_Dwelling_Hut         );
    Game::loadTexture( Res::getTexture( "Buildings/Dwellings/House"     ),  Texture_Name::Building_Dwelling_House       );

    Game::loadTexture( Res::getTexture( "Buildings/Wood/Woodcut_Hut"    ),  Texture_Name::Building_Wood_Woodcut_Hut     );

    Game::loadTexture( Res::getTexture( "Buildings/Stone/Small_Mine"    ),  Texture_Name::Building_Stone_Small_Mine     );

    Game::loadTexture( Res::getTexture( "Buildings/Metal/Ore_Refinery"  ),  Texture_Name::Building_Metal_Ore_Refinery   );

    Game::loadTexture( Res::getTexture( "Buildings/Food/Farm"           ),  Texture_Name::Building_Food_Farm            );

    m_city = std::make_unique<City>( "River City" );

    Log::logMessage( "Switched to Playing state", Log_Type::State_Switch );
}

void Playing :: input( float dt )
{

}

void Playing :: update( float dt )
{
    m_city        ->update( dt );
}

void Playing :: draw( float dt )
{
    m_city    ->draw();
}


void Playing :: setBuildingMode( /* */ )
{

}

}
