#ifndef GUI_FEATURE_H
#define GUI_FEATURE_H

#include <SFML/Graphics.hpp>

class GUI_Feature
{
    public:
        GUI_Feature(int xSize,
                    int ySize,
                    int xPos,
                    int yPos,
                    const sf::Vector2f& guiOffset,
                    const sf::Texture& texture );

        virtual void draw   () = 0;
        virtual void update () = 0;

    protected:
        sf::RectangleShape m_thing;
};

#endif // GUI_FEATURE_H
