#include "Game/Game.h"

void main()
{
	Game game = Game();

	int width = 800;
	int height = 640;
	const char* title = "GAME";

	game.RunEngine(width, height, title);
}