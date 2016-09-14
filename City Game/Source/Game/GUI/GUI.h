#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

#include "Button.h"

//dont judge me, this is my first time doing gui really

class GUI
{
    public:
        GUI             ( int width, int height, int xPos, int yPos );

        void setTexture     ( const sf::Texture& texture );
        void setBgColour    ( const sf::Color& colour );

        void addButton  ( const sf::Texture t,
                        int width,
                        int height,
                        int xPos,
                        int yPos,
                        std::function<void(void)> callback  );

        void update     ();
        void draw       ();



    private:
        sf::RectangleShape  m_background;

        std::vector<Button> m_buttons;
};

#endif // GUI_H
