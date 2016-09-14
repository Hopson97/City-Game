#ifndef MOUSE_H
#define MOUSE_H

#include <SFML/Graphics.hpp>

class Mouse
{
    public:
        Mouse();

        void update ( const sf::RenderWindow& window );

        bool isMouseDownLeft    () const;
        bool isMouseDownRight   () const;

        const sf::Vector2f& getPosition () const;

        void draw ( sf::RenderWindow& window );

    private:
        sf::Sprite  m_sprite;
        sf::Texture m_icon;
};

#endif // MOUSE_H
