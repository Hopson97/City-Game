#include "Builder.h"

#include "Building.h"


#include "../../Util/Mouse.h"
#include "../../Game.h"
#include "../../Managers/Resource_Identifier.h"
#include "../Level.h"

#include "Special_Button.h"

Builder :: Builder ( Level& level )
:   m_level     ( level )
,   m_buildMenu ( {BUILD_MENU_WIDTH, BUILD_MENU_HEIGHT}, {0, BUILD_MENU_SEC_Y} )
{
    using namespace std::placeholders;

     m_buildMenu     .setBgColour    ( { 100, 100, 100 } );

     const sf::Vector2f buttonSize ( 20, 20 );

     m_buildMenu.add ( std::make_unique<Special_Button<Building_Data>>( buttonSize,
                                                                        sf::Vector2f{ 10, 0  },
                                                                        m_buildMenu.getGUIOffset(),
                                                                        Game::getTexture( Texture_Name::Building_Dwelling_Hut ),
                                                                        std::bind ( &Builder::switchBuildType, this, &getBuildingData( Building_Name::House_Hut ) ),
                                                                        getBuildingData( Building_Name::House_Hut ) ));
}

void Builder :: input ()
{
    if ( m_state == Playing_State::Building ) {
        if ( Mouse::isLeftDown() ) {
            tryBuild();
        }
    }

    if ( Mouse::isRightDown() ) {
        m_state = Playing_State::None;
        m_currentData = nullptr;
    }
}

void Builder :: update ()
{
    checkIfCanBuild();
    m_buildMenu.update();
    m_preview.setPosition( Mouse::getPosition() );
}

void Builder :: draw   ()
{
    m_buildMenu .draw();

    if ( m_state == Playing_State::Building ) {
        Window::draw( m_preview );
    }
}

void Builder :: switchBuildType( Building_Data* data )
{
    m_state = Playing_State::Building;
    m_preview.setTexture( &data->getTexture ()  );
    m_preview.setSize   (  data->getSize    ()  );
    m_currentData = data;
}

void Builder :: tryBuild  ()
{
    if ( m_canBuild ) {
        m_level.addBuilding( std::make_shared<Building>( *m_currentData, m_preview.getPosition() ) );
    }
}

void Builder :: checkIfCanBuild()
{
    for ( auto& rect : m_level.getGroundSections() ) {
        if ( m_preview.getGlobalBounds().intersects( rect ) ) {
            m_canBuild = true;
        }
    }

    for ( auto& rect : m_level.getWaterSections() ) {
        if ( m_preview.getGlobalBounds().intersects( rect ) ) {
            m_canBuild = false;
        }
    }
}









