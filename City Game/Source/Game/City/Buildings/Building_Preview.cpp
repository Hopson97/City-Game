#include "Building_Preview.h"

// Set up the GUIs
Building_Preview::Building_Preview()
:   m_mainFrame     ( {200.f,100}, {Window::WIDTH-210, Window::HEIGHT-245} )
,   m_imagePreview  ( {55,40}, {Window::WIDTH-190, Window::HEIGHT-215} )
,   m_nameLabel     ( {180.f,0}, {Window::WIDTH-200, Window::HEIGHT-238} )
{
    m_mainFrame  .setBgColour    ( { 180, 180, 180, 100 } );
    m_mainFrame  .changeOutlineColour( {140, 140, 140, 80} );

    m_nameLabel  .setTitle("Building Name");
    m_nameLabel  .setBgColour ( {180, 0, 0, 120 } );
    m_nameLabel  .changeOutlineColour ( {180, 0, 0, 120 } );
    m_nameLabel  .changeOutlineThickness(3);


    this->state = PR_STATE::HIDE;
}

void Building_Preview::setImagePreview(const sf::Texture& texture)
{
    resetImagePreview();
    m_imagePreview.setTexture(texture);
}

void Building_Preview::changeState(PR_STATE state)
{
    this->state = state;
}

// Basic Functions to update everything
void Building_Preview::update()
{
    // Get rid of outline surrounding image (doesn't work in ctor)
    // TODO: Find a more efficient location for this rather than set it very frame
    //     : Right now the outline shows up for 1 frame before disappearing
    m_imagePreview  .changeOutlineThickness(0);

    // Update mainFrame
    m_mainFrame.update();
    m_imagePreview.update();
    m_nameLabel.update();
}

void Building_Preview::draw()
{
    // Only draws during Building Mode
    if ( this->state == PR_STATE::SHOW ) {
        m_mainFrame.draw();
        m_imagePreview.draw();
        m_nameLabel.draw();
    }
}


void Building_Preview::resetImagePreview()
{
    static sf::Vector2f previewSize ( 55, 40 );
    static sf::Vector2f previewPos  ( Window::WIDTH-190, Window::HEIGHT-215 );

    m_imagePreview = GUI ( previewSize, previewPos );
}
