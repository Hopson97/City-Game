#include "Builder.h"

#include "Building.h"


#include "../../Util/Mouse.h"
#include "../../Game.h"
#include "../../Managers/Resource_Identifier.h"
#include "../City.h"

#include "Special_Button.h"

Builder :: Builder ( City& City )
:   m_City     ( City )
,   m_buildMenu ( {BUILD_MENU_WIDTH, BUILD_MENU_HEIGHT}, {0, BUILD_MENU_SEC_Y} )

{
    using namespace std::placeholders;

     m_buildMenu.setBgColour    ( { 100, 100, 100 } );

     const sf::Vector2f buttonSize ( 20, 20 );
     m_buildMenu.beginRow( { 10, 0 }, 5 );

     m_buildMenu.addSpecialButton<Building_Data>
                                ( buttonSize,
                                Game::getTexture( Texture_Name::Building_Dwelling_Hut ),
                                getFunction( getBuildingData( Building_Name::House_Hut ) ),
                                getBuildingData( Building_Name::House_Hut ) );

         m_buildMenu.addSpecialButton<Building_Data>
                                ( buttonSize,
                                Game::getTexture( Texture_Name::Building_Dwelling_House ),
                                getFunction( getBuildingData( Building_Name::House ) ),
                                getBuildingData( Building_Name::House ) );
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
        m_buildPreview.changeState(PR_STATE::HIDE);
        m_currentData = nullptr;
    }
}

void Builder :: update ()
{
    checkIfCanBuild();
    m_buildPreview.update();
    m_buildMenu.update();
    m_preview.setPosition( Mouse::getPosition() );

    if ( !m_canBuild ) {
        m_preview.setFillColor( { 200, 100, 100, 200 } );
    } else {
        m_preview.setFillColor( sf::Color::White );
    }
}

void Builder :: draw   ()
{
    m_buildPreview.draw();
    m_buildMenu.draw();

    if ( m_state == Playing_State::Building ) {
        Window::draw( m_preview );
    }
}

void Builder :: switchBuildType( Building_Data* data )
{
    m_preview = sf::RectangleShape();   //Reset the preview, or else the texture is messed up on it

    m_state = Playing_State::Building;
    m_preview.setSize   (  data->getSize    ()  );

    m_buildPreview.changeState(PR_STATE::SHOW);
    m_buildPreview.setImagePreview( data->getTexture() );

    m_preview.setTexture( &data->getTexture ()  );
    m_currentData = data;
}

void Builder :: tryBuild  ()
{
    if ( m_canBuild ) {
        m_City.tryAddBuilding( std::make_shared<Building>( *m_currentData, m_preview.getPosition() ) );
    }
}

void Builder :: checkIfCanBuild()
{
    sf::FloatRect bottom = m_preview.getGlobalBounds();
    bottom.top += bottom.height - 7;
    bottom.height = 7;


    for ( auto& rect : m_City.getGroundSections() ) {
        if ( bottom.intersects( rect ) ) {
            m_canBuild = true;
        }
    }

    for ( auto& rect : m_City.getWaterSections() ) {
        if ( bottom.intersects( rect ) ) {
            m_canBuild = false;
        }
    }

    //Check for intersection with the other buildings, seeing as we don't want
    //buildings ontop of buildings as that wouldn't make sense tbh
    for ( auto& building : m_City.getBuildings() ) {
        if ( bottom.intersects( building->bounds ) ) {
           m_canBuild = false;
        }
    }
}

std::function<void(Building_Data*)> Builder :: getFunction( Building_Data& data )
{
    return std::bind ( &Builder::switchBuildType, this, &data );
}









