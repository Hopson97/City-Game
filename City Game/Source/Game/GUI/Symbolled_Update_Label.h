#ifndef SYMBOLLED_UPDATE_LABEL_H
#define SYMBOLLED_UPDATE_LABEL_H

#include <SFMl/Graphics.hpp>

#include "GUI_Feature.h"

class Symbolled_Update_Label : public GUI_Feature
{
    public:
        Symbolled_Update_Label( int xSize,
                                int ySize,
                                int xPos,
                                int yPos,
                                const sf::Vector2f& guiOffset,
                                const sf::Texture& m_symbol,
                                const int& value,
                                const std::string& toolTip );

        void update () override;
        void draw   () override;

    private:
        sf::RectangleShape m_symbol;
        sf::Text m_label;
        sf::Text m_tooltip;

        const int*    m_valueI;
};

#endif // SYMBOLLED_UPDATE_LABEL_H
