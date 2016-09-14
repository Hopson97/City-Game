#include "GUI.h"

#include "Mouse.h"
#include "Window.h"
#include "../Game.h"

GUI :: GUI ( int width, int height, int xPos, int yPos )
:   m_background   ( { (float)width, (float)height + m_topBarHeight } )
,   m_resizeButton ( { 20, m_topBarHeight }, { 2, 2 }, { (float)xPos, (float)yPos }, Game::getTexture( Texture_Name::GUI_Resize_Button), std::bind( GUI::reSize, this ) )
{
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
    m_background    .setFillColor( colour );
}


//Add a button
void GUI :: addButton( const sf::Vector2f& size,
                       const sf::Vector2f& position,
                       const sf::Texture&  texture,
                       std::function<void(void)> callback )
{
    m_features.push_back( std::make_unique<Button>
                        ( size, position, getGUIOffset(), texture, callback ) );
}

//Add an update label
void GUI :: addSymbolUpdateLabel(const sf::Vector2f& size,
                                 const sf::Vector2f& position,
                                 const sf::Texture& symbol,
                                 const int& value,
                                 const std::string& toolTip )
{
    m_features.push_back( std::make_unique<Symbolled_Update_Label>
                        ( size, position, getGUIOffset(), symbol, value, toolTip ));
}

void GUI :: setResizeable ( bool canResize )
{
    m_isResizable = canResize;
}



void GUI :: update()
{
    if ( m_isResizable ) {
        m_resizeButton.update();
    }

    for ( auto& feature : m_features ) {
        feature->update();
    }
}

void GUI :: draw()
{
    if ( !m_isHidden ) {
        Window::draw( m_background );

        for ( auto& feature : m_features ) {
            feature->draw();
        }
    }
    if ( m_isResizable ) {
        m_resizeButton.draw();
    }
}


sf::Vector2f GUI::getGUIOffset() const
{
    return { m_background.getPosition().x,
             m_background.getPosition().y + m_topBarHeight + 5 };
}


void GUI::reSize()
{
    m_isHidden = !m_isHidden;
}
