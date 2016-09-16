#include "Level.h"

#include "../Util/Window.h"

Level::Level( const std::string& name )
:   m_name ( name )
{
    m_background.setSize( { WIDTH, HEIGHT } );
    init();
}

void Level :: update( float dt)
{
    m_values.update();
}

void Level :: draw()
{
    Window::draw( m_background );

    m_values.draw();
}