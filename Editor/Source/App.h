#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Mouse.h"

enum class Mode
{
    Water,
    Collision,
    Ground
};

enum class State
{
    None,
    Rectangle
};

class App
{
    public:
        App     ( const std::string& texturePath );

        void run();

    private:
        void checkForClose();

        void input  ();
        void update ();
        void draw   ();

        void switchMode     ();

        void setUpRect      ();
        void updateRect     ();
        void addRect        ();
        void drawRects      ();
        void tryRemoveRect  ();

        void save           ();

        void iterateRemoveRect  ( std::vector<sf::RectangleShape>& rects );

        Mode    m_currentMode   = Mode::Water;

        Mouse   m_mouse;
        State   m_state;

        sf::RenderWindow m_window;
        sf::RectangleShape m_mapSprite;

        sf::Font m_font;
        sf::Text m_text;

        sf::Image mapImage;

        std::string m_modeString;
        const std::string texturePath;

        std::vector<sf::RectangleShape> m_waterRects;
        std::vector<sf::RectangleShape> m_groundRects;
        std::vector<sf::RectangleShape> m_collisionRects;

        sf::RectangleShape m_currentRect;

        static
        constexpr int   WIDTH  = 1280,
                        HEIGHT = 600;

};

#endif // APP_H
