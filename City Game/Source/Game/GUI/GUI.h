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

        void update     ();
        void draw       ();



    private:
        sf::RectangleShape  m_background;

        std::vector<std::unique_ptr<GUI_Feature>> m_features;
};

#endif // GUI_H
