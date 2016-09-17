#include "Building_Preview.h"

// Set up the GUIs
Building_Preview::Building_Preview()
:   m_mainFrame ( {200.f,100}, {Window::WIDTH-210, Window::HEIGHT-245} )
,   m_imagePreview( {55,40}, {Window::WIDTH-190, Window::HEIGHT-215} )
{
    m_mainFrame  .setBgColour    ( { 180, 180, 180, 100 } );

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
    // Update mainFrame

    m_mainFrame.update();
    m_imagePreview.update();
}

void Building_Preview::draw()
{
    if ( this->state == PR_STATE::SHOW ) {
        m_mainFrame.draw();
        m_imagePreview.draw();
    }
}


void Building_Preview::resetImagePreview()
{
    static sf::Vector2f previewSize ( 55, 40 );
    static sf::Vector2f previewPos  ( Window::WIDTH-190, Window::HEIGHT-215 );

    m_imagePreview = GUI ( previewSize, previewPos );
}
