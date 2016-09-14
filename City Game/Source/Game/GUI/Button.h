#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include <functional>

struct Button
{
    Button ( const sf::Texture t,
             int width,
             int height,
             int xPos,
             int yPos,
             std::function<void(void)> callback,
             const sf::Vector2f& guiPos
           );

    void checkForClick();

    sf::RectangleShape          m_button;

    std::function<void(void)>   m_function;
};

#endif // BUTTON_H
