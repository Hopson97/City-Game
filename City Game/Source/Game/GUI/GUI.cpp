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


//Add a button
void GUI :: addButton(const sf::Texture& t,
                      int width, int height,
                      int xPos,  int yPos,
                      std::function<void(void)>callback)
{
    m_features.push_back( std::make_unique<Button>
                          ( t,
                            width, height,
                            xPos, yPos,
                            callback,
                            m_background.getPosition() ) );


}


//Add an update label
void GUI :: addSymbolUpdateLabel(const sf::Texture& t,
                                 int width, int height,
                                 int xPos, int yPos,
                                 const int& value,
                                 const std::string& toolTip)
{
    Symbolled_Update_Label s( width, height,
                            xPos, yPos,
                            m_background.getPosition(),
                            t,
                            value,
                            toolTip );

    m_features.push_back( std::make_unique<Symbolled_Update_Label>
                          ( width, height,
                            xPos, yPos,
                            m_background.getPosition(),
                            t,
                            value,
                            toolTip ) );
}


void GUI :: update()
{
    for ( auto& feature : m_features )
    {
        feature->update();
    }
}

void GUI :: draw()
{
    Window::draw( m_background );

    for ( auto& feature : m_features )
    {
        feature->draw();
    }
}
