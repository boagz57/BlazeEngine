#include "Math/Vector3D.h"
#include "GameWorld/SceneManager.h"
#include "GameWorld/World.h"

World gameWorld;
SceneManager scene;

uint16 main()
{
	scene.Initialize();

	//LoadSound(char8* filePath, enum TYPE_OF_SOUND) { return Sound* };
	//PlaySound(Sound* sound);

	scene.CreatePlayer(BlazeFramework::Vector3D(0.0f, 0.0f, 0.0f), "Triangle");
	scene.CreateStaticEntity(BlazeFramework::Vector3D(0.0f, 0.4f, 0.0f), "Triangle");
	scene.CreateStaticEntity(BlazeFramework::Vector3D(0.8f, 0.4f, 0.0f), "Square");

	gameWorld.Initialize(scene);

	gameWorld.GameLoop(scene);

	gameWorld.Shutdown(scene);

	return 0;
}