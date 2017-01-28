#include "GameWorld/World/World.h"

World gameWorld;

int main()
{
	gameWorld.Initialize();

	gameWorld.GameLoop();

	gameWorld.Shutdown();

	return 0;
}