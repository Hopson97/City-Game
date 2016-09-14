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

        void onUpdate   () override;
        void draw       () override;

    private:
        void drawToolTip ();

        sf::RectangleShape m_symbol;
        sf::Text    m_label;
        sf::Text    m_tooltip;

        sf::Clock   m_toolTipTimer;
        bool        m_isToolTipActive = false;

        const int*    m_valueI;
};

#endif // SYMBOLLED_UPDATE_LABEL_H
