#include "Music_Manager.h"


void Music_Manager::playSong( const std::string& name )
{
    m_currentSong.stop();
    m_currentSong.openFromFile ( "Data/Music/" + name + ".ogg" );
    m_currentSong.setVolume ( 10 );
    m_currentSong.play();

    m_songTime = m_currentSong.getDuration().asSeconds();
    m_songTimer.restart();
}

bool Music_Manager :: finished () const
{
    return m_songTime <= m_songTimer.getElapsedTime().asSeconds() + 2;
}
