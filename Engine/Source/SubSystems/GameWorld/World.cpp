#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "SubSystems/RenderSystem.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Universal/Globals.h"
#include "World.h"

World::World()
{}

World::~World()
{}

bool World::Initialize()
{
	return true;
}

bool World::Shutdown()
{
	return true;
}

void World::GameLoop()
{
	RenderSystem renderer;
	renderer.Initialize();

	SceneManager scene;

	uint16 triangle = scene.CreateTriangle(BlazeFramework::Math::Vector2D(0.0f, 0.2f));

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		renderer.RenderScene(scene);

		window.Update();
	};
}