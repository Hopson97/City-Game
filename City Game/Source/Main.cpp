#include "Game/Game.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	srand ( time ( NULL ) );

	Game game;
	game.run();

	return 0;
}
