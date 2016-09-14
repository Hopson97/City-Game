#ifndef STATE_BASE_H_INCLUDED
#define STATE_BASE_H_INCLUDED

class Game;

#include "../Util/Debug_Log.h"

namespace State
{
	class State_Base
	{
		public:
			State_Base			( Game& game );

			virtual void input  ( float dt ) = 0;
			virtual void update ( float dt ) = 0;
			virtual void draw   ( float dt ) = 0;


		protected:
            Game& m_game;
	};
}

#endif // STATE_BASE_H_INCLUDED
