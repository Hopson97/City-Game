#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <memory>

#include "Button.h"
#include "Symbolled_Update_Label.h"

//dont judge me, this is my first time doing gui really
//it's ok, same here

class GUI
{
    public:
        GUI ( const sf::Vector2f& size, const sf::Vector2f& position );

        void setTexture     ( const sf::Texture& texture );
        void setBgColour    ( const sf::Color& colour );

        void add( std::unique_ptr<GUI_Feature> feature );

        void addButton  (   const sf::Vector2f& size,
                            const sf::Vector2f& position,
                            const sf::Texture&  texture,
                            std::function<void(void)> callback );

        void addSymbolUpdateLabel ( const sf::Vector2f& size,
                                    const sf::Vector2f& position,
                                    const sf::Texture& symbol,
                                    const int& value,
                                    const std::string& toolTip );


        void setResizeable ( bool canResize );

        void update     ();
        void draw       ();

        sf::Vector2f getGUIOffset () const;

    private:
        sf::RectangleShape  m_background;

        void reSize();

         Button m_resizeButton;
        bool m_isResizable   = false;
        bool m_isHidden      = false;

        constexpr static int m_topBarHeight = 10;

        std::vector<std::unique_ptr<GUI_Feature>> m_features;
};

#endif // GUI_H
