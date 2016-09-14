#include "state_base.h"

#include "../Game.h"

namespace State
{

State_Base :: State_Base( Game& game )
: m_game    ( game )
{
    Game::pushManagerStates();
}

}
