#ifndef MUSIC_MANAGER_H_INCLUDED
#define MUSIC_MANAGER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <map>
#include <memory>

class Music_Manager
{
    public:
        void playSong	( const std::string& name );

        bool finished   () const;

    private:
        sf::Music m_currentSong;
        sf::Clock m_songTimer;

        float m_songTime;
};

#endif
