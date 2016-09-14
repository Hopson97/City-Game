#include "App.h"

#include "Set_Up.h"

#include <iostream>

App :: App( const std::string& texturePath )
:   m_window    ( sf::VideoMode ( WIDTH, HEIGHT ), "City Game - Map/ Map section editor")
,   texturePath ( texturePath )
{
    m_mapSprite.setSize     ( { WIDTH, HEIGHT } );
    m_mapSprite.setTexture  ( &getMapTexture()  );

    m_font.loadFromFile     ( "Fonts/rs.ttf"    );

    m_text.setFont          ( m_font            );
    m_text.setColor         ( { 214, 239, 53 } ); //Yellow
    m_text.setCharacterSize( 20 );

    switchMode();

    m_window.setMouseCursorVisible( false );

    mapImage.loadFromFile( texturePath );
}


void App :: run()
{
    while ( m_window.isOpen () ) {
        input();
        update();
        draw();
    }
}



void App :: input()
{
    m_mouse.update( m_window );

    sf::Event e;
    while ( m_window.pollEvent ( e ) ) {
        if ( e.type == sf::Event::Closed )  {
            m_window.close();
        }
    }

    if ( m_state == State::None ) {
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::C ) ) {
            switchMode();
        }
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) ) {
            while ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) );
            save();
        }
        if ( m_mouse.isMouseDownLeft() ) {
            m_state = State::Rectangle;
            setUpRect();
        }
        if ( m_mouse.isMouseDownRight() ) {
            tryRemoveRect  ();
        }
    }
    else if ( m_state == State::Rectangle ) {
        if ( !m_mouse.isMouseDownLeft() ) {
            addRect();
            m_state = State::None;
        }
    }

}



void App :: update()
{
    if ( m_state == State::Rectangle ) {
        updateRect();
    }
}



void App :: draw()
{
    m_window.clear  ();
    m_window.draw   ( m_mapSprite );
    m_window.draw   ( m_text );
    drawRects();
    m_mouse.draw( m_window );

    m_window.display ();
}



void App :: switchMode()
{
    static std::string waterString      = "Water";
    static std::string collisionString  = "Non-Build Zones";
    static std::string buildableString  = "Build Zones";

    static std::string start = "Press C to switch mode. Current Mode: ";
    static std::string end = "\nClick and drag to draw a zone. \nPress S to save. ";

    switch ( m_currentMode )
    {
        case Mode::Water:
            m_currentMode = Mode::Collision;
            m_modeString = start + collisionString;
            break;

        case Mode::Collision:
            m_currentMode = Mode::Ground;
            m_modeString = start + buildableString;
            break;

        case Mode::Ground:
            m_currentMode = Mode::Water;
            m_modeString = start + waterString;
            break;
    }

    m_text.setString( m_modeString + end );
}


void App :: setUpRect()
{
    m_currentRect.setPosition( m_mouse.getPosition() );
    m_currentRect.setSize( { 0, 0 } );
    m_currentRect.setOutlineColor( sf::Color::Black );
    m_currentRect.setOutlineThickness( 2 );

    switch ( m_currentMode )
    {
        case Mode::Water:
            m_currentRect.setFillColor( { 100, 100, 255, 100 } );
            break;

        case Mode::Ground:
            m_currentRect.setFillColor( { 100, 255, 100, 100 } );
            break;

        case Mode::Collision:
            m_currentRect.setFillColor( { 255, 100, 100, 100 } );
            break;
    }
}

void App :: updateRect()
{
    float xOffset = m_currentRect.getPosition().x - m_mouse.getPosition().x;
    float yOffset = m_currentRect.getPosition().y - m_mouse.getPosition().y;

    xOffset = -xOffset;
    yOffset = -yOffset;

    m_currentRect.setSize( { xOffset, yOffset } );
}


void App :: addRect()
{
    float x     =   m_currentRect.getPosition().x;
    float y     =   m_currentRect.getPosition().y;
    float x2    =   x + m_currentRect.getGlobalBounds().width;
    float y2    =   y + m_currentRect.getGlobalBounds().height;

    float width     = m_currentRect.getGlobalBounds().width;
    float height    = m_currentRect.getGlobalBounds().height;

    if ( x < 0 ) m_currentRect.setPosition( 0, y );
    if ( y < 0 ) m_currentRect.setPosition( x, 0 );

    if ( x2 > WIDTH  ) {
        float amount = width - WIDTH;
        m_currentRect.setSize( { width - amount, height } );
    }
    if ( y2 > HEIGHT  ) {
        float amount = height - HEIGHT;
        m_currentRect.setSize( { WIDTH, height - amount } );
    }


    m_currentRect.setOutlineThickness( 0 );
    switch ( m_currentMode )
    {
        case Mode::Water:
            m_currentRect.setFillColor( { 100, 100, 200, 100 } );
            m_waterRects.push_back( m_currentRect );
            break;

        case Mode::Ground:
            m_currentRect.setFillColor( { 100, 200, 100, 100 } );
            m_groundRects.push_back( m_currentRect );
            break;

        case Mode::Collision:
            m_currentRect.setFillColor( { 200, 100, 100, 100 } );
            m_collisionRects.push_back( m_currentRect );
            break;
    }
}

void App :: drawRects ()
{
    for ( auto& rect : m_groundRects ) {
        m_window.draw( rect );
    }
    for ( auto& rect : m_waterRects ) {
        m_window.draw( rect );
    }
    for ( auto& rect : m_collisionRects ) {
        m_window.draw( rect );
    }

    if ( m_state == State::Rectangle ) {
        m_window.draw ( m_currentRect );
    }
}

void App :: tryRemoveRect  ()
{
    switch ( m_currentMode )
    {
        case Mode::Water:
            iterateRemoveRect( m_waterRects );
            break;

        case Mode::Ground:
            iterateRemoveRect( m_groundRects );
            break;

        case Mode::Collision:
            iterateRemoveRect( m_collisionRects );
            break;
    }
}


void App :: iterateRemoveRect ( std::vector<sf::RectangleShape>& rects )
{
    for ( size_t i = 0 ; i < rects.size() ; i++ ) {
        auto& rect = rects.at( i );
        if ( rect.getGlobalBounds().contains ( m_mouse.getPosition() ) ) {
            rects.erase ( rects.begin() + i );
        }
    }
}
