#ifndef GUI_FEATURE_H
#define GUI_FEATURE_H

#include <SFML/Graphics.hpp>
#include <functional>

class GUI_Feature
{
    public:
        GUI_Feature(int xSize,
                    int ySize,
                    int xPos,
                    int yPos,
                    const sf::Vector2f& guiOffset,
                    const sf::Texture& texture );

        virtual void draw       () = 0;
        virtual void onUpdate   () = 0;
        void update ();

    protected:
        void addRollOverFunction ( std::function<void(void)> f );

        sf::RectangleShape m_thing;
        std::function<void(void)> m_rollOverfunction;
        bool m_hasRollOverFunction = false;
};

#endif // GUI_FEATURE_H
