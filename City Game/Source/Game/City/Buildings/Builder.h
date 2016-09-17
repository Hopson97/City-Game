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
        Builder( City& City );

        void input  ();
        void update ();
        void draw   ();

    private:
        void switchBuildType( Building_Data* data );
        void tryBuild       ();
        void checkIfCanBuild();

        std::function<void(Building_Data*)> getFunction(  Building_Data& data );

        sf::RectangleShape m_preview;

        City&  m_City;
        GUI     m_buildMenu;
        Building_Preview m_buildPreview;

        Playing_State m_state = Playing_State::None;

        Building_Data* m_currentData = nullptr;

        bool m_canBuild = false;

        constexpr static float  BUILD_MENU_SEC_Y  = 600, //Where the build menu starts
                                BUILD_MENU_WIDTH  = Window::WIDTH,
                                BUILD_MENU_HEIGHT = 120;
};

#endif // BUILDER_H
