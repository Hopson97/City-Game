#include "Building_Preview.h"

// Set up the GUIs
Building_Preview::Building_Preview()
:   m_mainFrame ( {200,100}, {Window::WIDTH-210,  200 - 130} )
{
    m_mainFrame  .setBgColour    ( { 100, 100, 100 } );
}

// Basic Functions to update everything
void Building_Preview::update()
{
    m_mainFrame.update();
}

void Building_Preview::draw()
{
    m_mainFrame.draw();
}
