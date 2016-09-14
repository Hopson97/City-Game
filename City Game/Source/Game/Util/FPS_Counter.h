#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

class FPS_Counter
{
    public:
        FPS_Counter ();

        void update     ();
        void drawFPS    ();

    private:
        float getFPS( const sf::Time& time );

        void printFPS ( float framesPerSecond );

    private:
        sf::Clock   fpsClock;
        sf::Clock   fpsClock2;
        int         fpsCount  = 0;
        float       frameTimes  = 0;

        int         frameCount      = 0;
        float       frameTimes10    = 0; //Shows average FPS every 10 secs

        sf::Text m_fpsText;
};

#endif // FPS_COUNTER_H
