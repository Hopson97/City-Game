#include "FPS_Counter.h"

#include <string>
#include <iostream>

#include "Debug_Log.h"
#include "../Game.h"
#include "Window.h"

FPS_Counter :: FPS_Counter ()
{
    m_fpsText.setFont ( Game::getFont( Font_Name::Rs ) );
    m_fpsText.setCharacterSize ( 20 );
}

void FPS_Counter :: update ()
{

    float fpsThisFrame = getFPS( fpsClock.restart() );
    frameTimes      += fpsThisFrame;

    fpsCount ++;

    if ( fpsClock2.getElapsedTime().asSeconds() >= 0.2 ) {
        float fps = frameTimes / fpsCount;
        //printFPS ( frameTimes / fpsCount );
        frameTimes  = 0;
        fpsCount    = 0;
        fpsClock2.restart();
        frameCount ++;


        m_fpsText.setString ( "FPS: " + std::to_string ( fps ));
    }
}

float FPS_Counter :: getFPS( const sf::Time& time )
{
    return (1000000.0f / time.asMicroseconds());
}

void FPS_Counter :: printFPS ( float framesPerSecond )
{
    Log::makeGap();
    Log::logMessage( "Current FPS: " + std::to_string ( framesPerSecond ), Log_Type::FPS );
    Log::makeGap();
}

void FPS_Counter :: drawFPS()
{
    Window::draw( m_fpsText );
}
