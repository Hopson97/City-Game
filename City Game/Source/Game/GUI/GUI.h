#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <memory>

#include "Button.h"
#include "Symbolled_Update_Label.h"
#include "Special_Button.h"

//dont judge me, this is my first time doing gui really
//it's ok, same here

class GUI
{
    class Positioner
    {
        public:
            Positioner () = default;
            Positioner ( const sf::Vector2f& beginPosition, int padding )
            :   padding ( padding )
            ,   xPos    ( beginPosition.x )
            ,   yPos    ( beginPosition.y )
            {}

            virtual sf::Vector2f getPosition ( int ) = 0;

            bool active = false;

        protected:
            int padding;
            int xPos;
            int yPos;

    };

    class Column : public Positioner
    {
        public:
            Column () = default;
            Column ( const sf::Vector2f& beginPosition,  int padding )
            :   Positioner ( beginPosition, padding )
            {}


            sf::Vector2f getPosition ( int sectionHeight ) override
            {
                sf::Vector2f pos ( xPos, yPos );
                yPos += padding + sectionHeight;
                return pos;
            }
    };

    class Row : public Positioner
    {
        public:
            Row () = default;
            Row ( const sf::Vector2f& beginPosition, int padding )
            :   Positioner ( beginPosition, padding )
            {}

            sf::Vector2f getPosition ( int sectionWidth ) override
            {
                sf::Vector2f pos ( xPos, yPos );
                xPos += padding + sectionWidth;
                return pos;
            }
    };

    public:
        GUI ( const sf::Vector2f& size, const sf::Vector2f& position );

        void setTexture     ( const sf::Texture& texture );
        void setBgColour    ( const sf::Color& colour );

        void add( std::unique_ptr<GUI_Feature> feature );


        void addButton  (   const sf::Vector2f& size,
                            const sf::Texture&  texture,
                            std::function<void(void)> callback );

        void addSymbolUpdateLabel ( const sf::Vector2f& size,
                                    const sf::Texture& symbol,
                                    const int& value,
                                    const std::string& toolTip );


        void setResizeable ( bool canResize );

        void update         ();
        void draw           ();

        void beginColumn    ( const sf::Vector2f& beginPosition, int padding );
        void beginRow       ( const sf::Vector2f& beginPosition, int padding );

        void reSize();

    private:
        bool stylersActive  () const;

        sf::Vector2f getGUIOffset () const;


        sf::RectangleShape  m_background;

        Button m_resizeButton;
        bool m_isResizable   = false;
        bool m_isHidden      = false;

        Positioner* m_activePositioner;
        Column  m_column;
        Row     m_row;

        constexpr static int m_topBarHeight = 10;

        std::vector<std::unique_ptr<GUI_Feature>> m_features;

    public:
        template <typename Function_Arg>
        void addSpecialButton ( const sf::Vector2f& size,
                                const sf::Texture&  texture,
                                std::function<void(Function_Arg*)> callback,
                                Function_Arg& arg )
        {
            if ( !stylersActive() ) return;
            auto position = m_activePositioner->getPosition( size.y );

            m_features.push_back( std::make_unique<Special_Button<Function_Arg>>
                                ( size,
                                  position,
                                  getGUIOffset(),
                                  texture,
                                  callback,
                                  arg ) );
        }
};

#endif // GUI_H
