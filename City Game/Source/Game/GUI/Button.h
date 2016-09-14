#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include <functional>

#include "GUI_Feature.h"

class Button : public GUI_Feature
{
    public:
        Button (    const sf::Vector2f& size,
                    const sf::Vector2f& position,
                    const sf::Vector2f& guiPos,
                    const sf::Texture&  texture,
                    std::function<void(void)> callback
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
