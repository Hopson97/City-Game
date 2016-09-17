#include "City_Values.h"

#include "../Util/Window.h"
#include "../Game.h"
#include "../Managers/Resource_Identifier.h"

constexpr static int EXPLOIT_MODE = 9'999'999;

City_Values::City_Values()
:   m_resources     ( 200, 25, 25, 25, 25 )
//:   m_resources     ( EXPLOIT_MODE, EXPLOIT_MODE, EXPLOIT_MODE, EXPLOIT_MODE, EXPLOIT_MODE )
,   m_resourceGUI   ( {100, 185}, {Window::WIDTH - 100, 0} )
,   m_statsGUI      ( {100, 185}, {0,0 } )
{
    m_resourceGUI   .setBgColour    ( { 100, 100, 100 } );
    m_statsGUI      .setBgColour    ( { 100, 100, 100 } );

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

void City_Values :: newDay()
{
    m_resources += m_dailyResourceChange;
}

void City_Values :: setUpResourceGUI()
{
    const sf::Vector2f symbolSize ( 32, 32 );
    const int gap = 4;//Padding between the symbols
    int increase = symbolSize.y + gap;
    sf::Vector2f position ( gap, 1 );

    m_resourceGUI.add( std::make_unique<Symbolled_Update_Label> ( symbolSize,
                                                                  position,
                                                                  m_resourceGUI.getGUIOffset(),
                                                                  Game::getTexture( Texture_Name::Resource_Coins),
                                                                  m_resources.coins,
                                                                  "The amount of coins you have."  ) );
    position.y += increase;

    m_resourceGUI.add( std::make_unique<Symbolled_Update_Label> ( symbolSize,
                                                                  position,
                                                                  m_resourceGUI.getGUIOffset(),
                                                                  Game::getTexture( Texture_Name::Resource_Logs),
                                                                  m_resources.wood,
                                                                  "The amount of logs you have." ) );
    position.y += increase;

    m_resourceGUI.add( std::make_unique<Symbolled_Update_Label> ( symbolSize,
                                                                  position,
                                                                  m_resourceGUI.getGUIOffset(),
                                                                  Game::getTexture( Texture_Name::Resource_Stones),
                                                                  m_resources.stone,
                                                                  "The amount of stone you have." ) );
    position.y += increase;

    m_resourceGUI.add( std::make_unique<Symbolled_Update_Label> ( symbolSize,
                                                                  position,
                                                                  m_resourceGUI.getGUIOffset(),
                                                                  Game::getTexture( Texture_Name::Resource_Metal),
                                                                  m_resources.metal,
                                                                  "The amount of metal you have." ) );

    position.y += increase;

    m_resourceGUI.add( std::make_unique<Symbolled_Update_Label> ( symbolSize,
                                                                  position,
                                                                  m_resourceGUI.getGUIOffset(),
                                                                  Game::getTexture( Texture_Name::Resource_Food),
                                                                  m_resources.food,
                                                                  "The amount of food you have." ) );
}




void City_Values::setUpStatisticGUI()
{
    const sf::Vector2f symbolSize ( 32, 32 );
    const int gap = 4;//Padding between the symbols
    int increase = symbolSize.y + gap;
    sf::Vector2f position ( gap, 1 );

    m_statsGUI.addSymbolUpdateLabel(    symbolSize,
                                        position,
                                        Game::getTexture( Texture_Name::Stat_Population),
                                        m_statistics.population,
                                        "Population living in your city." );
    position.y += increase;

    m_statsGUI.addSymbolUpdateLabel(    symbolSize,
                                        position,
                                        Game::getTexture( Texture_Name::Stat_Unemployed),
                                        m_statistics.population,
                                        "Unemployed people looking for work." );
    position.y += increase;

    m_statsGUI.addSymbolUpdateLabel(    symbolSize,
                                        position,
                                        Game::getTexture( Texture_Name::Stat_Vacancy ),
                                        m_statistics.vacancy,
                                        "Vacant housing  spaces in your city." );
    position.y += increase;

    m_statsGUI.addSymbolUpdateLabel(    symbolSize,
                                        position,
                                        Game::getTexture( Texture_Name::Stat_Happiness ),
                                        m_statistics.happiness,
                                        "The overall happiness of your people." );
    position.y += increase;
}
