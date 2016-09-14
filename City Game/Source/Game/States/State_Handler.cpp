#include "State_Handler.h"

void State_Handler::pushState( StatePtr state )
{
	m_states.push(std::move(state));
}


bool State_Handler::popState()
{
	if ( !m_states.empty() ) {
		m_states.pop();
		return true;
	}
	return false;
}

StatePtr& State_Handler::peekState()
{
	return m_states.top();
}
