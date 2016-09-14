#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include <functional>

#include "GUI_Feature.h"

class Button : public GUI_Feature
{
    public:
        Button ( const sf::Texture& t,
                int width,
                int height,
                int xPos,
                int yPos,
                std::function<void(void)> callback,
                const sf::Vector2f& guiPos
            );

        void draw       () override;
        void onUpdate   () override;

    private:
        void checkForClick();

        bool m_isActive = false;
        sf::Clock m_activeTimer;

        std::function<void(void)>   m_function;
};

#endif // BUTTON_H
