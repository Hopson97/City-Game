#ifndef STATE_HANDLER_H_INCLUDED
#define STATE_HANDLER_H_INCLUDED

#include <stack>
#include "state_base.h"

#include <memory>

typedef std::unique_ptr<State::State_Base> StatePtr;

class State_Handler
{

	public:
		void pushState	( StatePtr state );
		bool popState	();

		StatePtr& peekState();

	private:
		std::stack<StatePtr> m_states;
};

#endif // STATE_HANDLER_H_INCLUDED
