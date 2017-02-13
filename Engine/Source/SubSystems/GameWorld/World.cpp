#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "RenderSystem.h"
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
	SceneManager scene;

	uint16 triangle = scene.CreateTriangle(BlazeFramework::Math::Vector2D(0.0f, 0.2f));

	InitializeRenderSystem();
	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		RenderSystem(scene);

		window.Update();
	};
}