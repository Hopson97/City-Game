#include "Music_Manager.h"


void Music_Manager::playSong( const std::string& name )
{
	if ( m_currentSong )
    {
        m_currentSong->stop();
    }
    m_currentSong = std::make_unique<sf::Music>();
    m_currentSong->openFromFile ( "Data/Music/" + name + ".ogg" );
    m_currentSong->play();
    m_currentSong->setLoop( true );
}



