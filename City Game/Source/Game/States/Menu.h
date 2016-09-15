#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../Game.h"
#include "State_Base.h"

namespace State
{
	class Menu : public State_Base
	{
		public:
			Menu		( Game& game );

			void input	( float dt ) override;
			void update	( float dt ) override;
			void draw	( float dt ) override;
	};
}

#endif // MENU_H_INCLUDED
