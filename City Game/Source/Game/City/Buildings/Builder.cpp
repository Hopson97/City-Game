#include "Builder.h"

#include "Building.h"


#include "../../Util/Mouse.h"
#include "../../Game.h"
#include "../../Managers/Resource_Identifier.h"
#include "../City.h"

#include "Special_Button.h"

Builder :: Builder ( City& City, const City_Values& values )
:   m_City          ( City )
,   m_cityValues    ( values )
,   m_buildMenu     ( {BUILD_MENU_WIDTH, BUILD_MENU_HEIGHT}, {0, BUILD_MENU_SEC_Y} )

{
    using namespace std::placeholders;

    m_cannotBuildText.setFont( Game::getFont( Font_Name::Rs ) );
    m_cannotBuildText.setCharacterSize( 15 );

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

    m_buildMenu.addSpecialButton<Building_Data>
                                ( buttonSize,
                                Game::getTexture( Texture_Name::Building_Wood_Woodcut_Hut ),
                                getFunction( getBuildingData( Building_Name::Wood_Woodcut_Hut ) ),
                                getBuildingData( Building_Name::Wood_Woodcut_Hut     ) );

    m_buildMenu.addSpecialButton<Building_Data>
                                ( buttonSize,
                                Game::getTexture( Texture_Name::Building_Stone_Small_Mine ),
                                getFunction( getBuildingData( Building_Name::Stone_Small_Mine ) ),
                                getBuildingData( Building_Name::Stone_Small_Mine     ) );
}

void Builder :: input ()
{
    if ( m_state == Playing_State::Building ) {
        if ( Mouse::isLeftDown() ) {
            tryBuild();

            if ( !m_canBuild ) {
                m_tooltipTimer.restart();
            }
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

    m_cannotBuildText.setPosition( Mouse::getPosition().x,
                                   Mouse::getPosition().y - m_cannotBuildText.getGlobalBounds().height );

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
        if ( m_tooltipTimer.getElapsedTime().asSeconds() < 1.5 ) {
            Window::draw( m_cannotBuildText );
        }
    }
}

void Builder :: switchBuildType( Building_Data* data )
{
    m_preview = sf::RectangleShape();   //Reset the preview, or else the texture is messed up on it

    m_state = Playing_State::Building;
    m_preview.setSize   (  data->getSize    ()  );

    m_buildPreview.changeState(PR_STATE::SHOW);
    m_buildPreview.setImagePreview( data->getTexture() );

    m_cannotBuildText.setString( "" );

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
    static const std::string waterError     = "Cannot build on water.";
    //static const std::string nonBuildError  = "Cannot build here.";
    //static const std::string groundError    = "Cannot build on ground.";

    static const std::string collisionEorr  = "Cannot build a building on a building.";

    static const std::string resourceError  = "Not enough resources to build.";

    sf::FloatRect bottom = m_preview.getGlobalBounds();
    bottom.top += bottom.height - 7;
    bottom.height = 7;


    for ( auto& rect : m_City.getGroundSections() ) {
        if ( bottom.intersects( rect ) ) {
            m_canBuild = true;
            //m_cannotBuildText.setString( waterError );
        }
    }

    for ( auto& rect : m_City.getWaterSections() ) {
        if ( bottom.intersects( rect ) ) {
            m_canBuild = false;
            m_cannotBuildText.setString( waterError );
        }
    }

    //Check for intersection with the other buildings, seeing as we don't want
    //buildings ontop of buildings as that wouldn't make sense tbh
    for ( auto& building : m_City.getBuildings() ) {
        if ( bottom.intersects( building->bounds ) ) {
           m_canBuild = false;
           m_cannotBuildText.setString( collisionEorr );
        }
    }

    if ( m_currentData ) {
        if ( m_currentData->getCost() > m_cityValues.m_resources ) {
            m_canBuild = false;
            m_cannotBuildText.setString( resourceError );
        }
    }
}

std::function<void(Building_Data*)> Builder :: getFunction( Building_Data& data )
{
    return std::bind ( &Builder::switchBuildType, this, &data );
}









