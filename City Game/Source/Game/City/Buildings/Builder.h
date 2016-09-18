#ifndef BUILDER_H
#define BUILDER_H

#include <functional>

#include "../../GUI/GUI.h"

#include "../../Util/Window.h"

#include "Building_Data.h"
#include "Building_Preview.h"

class City;

class Builder
{
    enum class Playing_State
    {
        None,
        Building
    };


    public:
        Builder( City& City, const City_Values& values );

        void input  ();
        void update ();
        void draw   ();

        constexpr static float  BUILD_MENU_SEC_Y  = 600, //Where the build menu starts
                                BUILD_MENU_WIDTH  = Window::WIDTH,
                                BUILD_MENU_HEIGHT = 120;

    private:
        void switchBuildType( Building_Data* data );
        void tryBuild       ();
        void checkIfCanBuild();

        std::function<void(Building_Data*)> getFunction(  Building_Data& data );

        sf::RectangleShape  m_preview;
        sf::Text            m_cannotBuildText;
        sf::Clock           m_tooltipTimer;

        City&  m_City;
        const City_Values& m_cityValues;

        GUI m_buildMenu;
        Building_Preview m_buildPreview;


        Playing_State m_state = Playing_State::None;

        Building_Data* m_currentData = nullptr;

        bool m_canBuild = false;
};

#endif // BUILDER_H
