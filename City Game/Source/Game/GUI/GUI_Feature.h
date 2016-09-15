#ifndef GUI_FEATURE_H
#define GUI_FEATURE_H

#include <SFML/Graphics.hpp>

#include <functional>

class GUI_Feature
{
    public:
        GUI_Feature (   const sf::Vector2f& size,
                        const sf::Vector2f& position,
                        const sf::Vector2f& guiPos,
                        const sf::Texture&  texture );
        void update ();
        virtual void draw       () = 0;

    protected:
        void addRollOverFunction ( std::function<void(void)> f );

        sf::RectangleShape m_thing;
        std::function<void(void)> m_rollOverfunction;
        bool m_hasRollOverFunction = false;

    private:
        virtual void onUpdate   () = 0;
};

#endif // GUI_FEATURE_H
