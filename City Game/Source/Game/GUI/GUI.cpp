#include "GUI.h"

#include "Mouse.h"
#include "Window.h"

GUI :: GUI ( int width, int height, int xPos, int yPos )
{
    m_background.setSize    ( { (float)width, (float)height } );
    m_background.setPosition( xPos, yPos );
    m_background.setOutlineThickness( 2 );
    m_background.setOutlineColor( sf::Color::Black );
}

void GUI :: setTexture(const sf::Texture& texture)
{
    m_background.setTexture( &texture );
}


void GUI :: setBgColour ( const sf::Color& colour )
{
    m_background.setFillColor( colour );
}


void GUI :: addButton(const sf::Texture t, int width, int height, int xPos, int yPos, std::function<void(void)>callback)
{
    m_buttons.emplace_back( t, width, height, xPos, yPos, callback, m_background.getPosition() );
}

void GUI :: update()
{
    for ( auto& button : m_buttons )
    {
        button.checkForClick();
    }
}

void GUI :: draw()
{
    Window::draw( m_background );

    for ( auto& button : m_buttons )
    {
        Window::draw( button.m_button );
    }
}
