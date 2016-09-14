#ifndef MUSIC_MANAGER_H_INCLUDED
#define MUSIC_MANAGER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <map>
#include <memory>

class Music_Manager
{
    public:
        void playSong	( const std::string& name );

    private:
        std::unique_ptr<sf::Music> m_currentSong;
};

#endif
