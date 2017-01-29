#include "GameWorld/World/World.h"

World gameWorld;

uint16 main()
{
	gameWorld.Initialize();

	gameWorld.GameLoop();

	gameWorld.Shutdown();

	return 0;
}