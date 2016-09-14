#ifndef STATE_PLAYING_H
#define STATE_PLAYING_H

#include "../game.h"
#include "state_base.h"

#include "../Util/Window.h"
#include "../Util/Mouse.h"

#include "../GUI/GUI.h"

#include "../Main/Level.h"

namespace State
{
	class Playing : public State_Base
	{
	    struct Resources
	    {
	        int coins   = 100;
	        int wood    = 10;
	        int stone   = 10;
	        int metal   = 10;
	        int food    = 10;
	    };

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

        private:
            constexpr static float  MENU_SEC_Y  = 600, //Where the menu starts
                                    MENU_WIDTH  = Window::WIDTH,
                                    MENU_HEIGHT = 120;

            Playing_State m_state = Playing_State::None;

            GUI         m_buildMenu;
            Level       m_level;
            Resources   m_resources;

	};
}

#endif // STATE_PLAYING_H
