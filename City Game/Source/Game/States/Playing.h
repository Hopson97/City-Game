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
            std::unique_ptr<Level> m_level;
	};
}

#endif // STATE_PLAYING_H
