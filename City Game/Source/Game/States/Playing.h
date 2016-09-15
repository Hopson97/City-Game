#ifndef STATE_PLAYING_H
#define STATE_PLAYING_H

#include "State_Base.h"

#include "../Game.h"

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

	    struct Statistics
	    {
	        int population              = 0;
	        int unemployedPopulation    = 0;
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

            void setUpResourceGUI   ();
            void setUpStatisticGUI  ();

        private:
            constexpr static float  BUILD_MENU_SEC_Y  = 600, //Where the build menu starts
                                    BUILD_MENU_WIDTH  = Window::WIDTH,
                                    BUILD_MENU_HEIGHT = 120;

            Playing_State m_state = Playing_State::None;

            GUI         m_buildMenu;
            GUI         m_resourceGUI;
            GUI         m_statsGUI;
            Level       m_level;
            Resources   m_resources;
            Statistics  m_statistics;

	};
}

#endif // STATE_PLAYING_H
