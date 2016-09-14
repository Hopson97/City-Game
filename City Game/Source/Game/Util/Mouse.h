#ifndef MOUSE_H
#define MOUSE_H

#include <SFML/Graphics.hpp>

namespace Mouse
{
        void init();

        void update ();

        bool isLeftDown    ();
        bool isRightDown   ();

        const sf::Vector2f& getPosition ();

        void draw ();
};

#endif // MOUSE_H
