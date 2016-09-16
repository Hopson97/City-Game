#ifndef STATE_PLAYING_H
#define STATE_PLAYING_H

#include <memory>

#include "State_Base.h"

#include "../Game.h"

#include "../Util/Window.h"
#include "../Util/Mouse.h"

#include "../GUI/GUI.h"

#include "../Level/Level.h"

namespace State
{
	class Playing : public State_Base
	{
	    enum class Playing_State
	    {
	        None,
	        Building
	    };

		public:
			Playing		( Game& game );

			void input	( float dt ) override;
			void update	( float dt ) override;
			void draw	( float dt ) override;

        private:
            void setBuildingMode ( /* */ );

            void setUpResourceGUI   ();
            void setUpStatisticGUI  ();

        private:
            constexpr static float  BUILD_MENU_SEC_Y  = 600, //Where the build menu starts
                                    BUILD_MENU_WIDTH  = Window::WIDTH,
                                    BUILD_MENU_HEIGHT = 120;

            Playing_State m_state = Playing_State::None;

            GUI         m_buildMenu;

            std::unique_ptr<Level> m_level;
	};
}

#endif // STATE_PLAYING_H
