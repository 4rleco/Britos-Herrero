#include "Game/Game.h"

void main()
{
	Triangle triangle = Triangle(0.0f, 0.0f, 0.0f, 0.5f, 0.5f);

	Game game = Game(triangle);

	int width = 800;
	int height = 640;
	const char* title = "GAME";

	game.RunEngine(width, height, title);
}