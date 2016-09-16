#ifndef BUILDER_H
#define BUILDER_H

#include "../../GUI/GUI.h"

#include "../../Util/Window.h"

#include "Building_Data.h"

class Level;

class Builder
{
    enum class Playing_State
    {
        None,
        Building
    };


    public:
        Builder( Level& level );

        void input  ();
        void update ();
        void draw   ();

    private:
        void switchBuildType( Building_Data* data );
        void tryBuild       ();
        void checkIfCanBuild();

        sf::RectangleShape m_preview;

        Level&  m_level;
        GUI     m_buildMenu;

        Playing_State m_state = Playing_State::None;

        Building_Data* m_currentData = nullptr;

        bool m_canBuild = false;

        constexpr static float  BUILD_MENU_SEC_Y  = 600, //Where the build menu starts
                                BUILD_MENU_WIDTH  = Window::WIDTH,
                                BUILD_MENU_HEIGHT = 120;
};

#endif // BUILDER_H
