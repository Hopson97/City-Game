#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <memory>

#include "Button.h"
#include "Symbolled_Update_Label.h"

//dont judge me, this is my first time doing gui really

class GUI
{
    public:
        GUI             ( int width, int height, int xPos, int yPos );

        void setTexture     ( const sf::Texture& texture );
        void setBgColour    ( const sf::Color& colour );

        void addButton  (   const sf::Texture& t,
                            int width,
                            int height,
                            int xPos,
                            int yPos,
                            std::function<void(void)> callback  );

        void addSymbolUpdateLabel ( const sf::Texture& t,
                                    int width,
                                    int height,
                                    int xPos,
                                    int yPos,
                                    const int& value,
                                    const std::string& toolTip );

        void setResizeable ( bool canResize );

        void update     ();
        void draw       ();



    private:
        sf::RectangleShape  m_background;

        sf::Vector2f getGUIOffset () const;

        void reSize();

         Button m_resizeButton;
        bool m_isResizable   = false;
        bool m_isHidden      = false;

        constexpr static int m_topBarHeight = 10;

        std::vector<std::unique_ptr<GUI_Feature>> m_features;
};

#endif // GUI_H
