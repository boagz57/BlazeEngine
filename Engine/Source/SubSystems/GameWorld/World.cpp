#include "Precompiled.h"
#include "Input/InputSystem.h"
#include "Graphics/RenderSystem.h"
#include "Physics/MovementSystem.h"
#include "GameWorld/SceneManager.h"
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
	MovementSystem movement;
	InputSystem input;
	RenderSystem renderer;
	SceneManager scene;

	scene.Initialize();
	movement.Initialize();
	input.Initialize();
	renderer.Initialize();

	//Player
	scene.CreateTriangle(BlazeFramework::Math::Vector2D(0.0f, 0.0f));
	//Scenery
	scene.CreateStaticEntity(BlazeFramework::Math::Vector2D(0.0f, 0.4f));

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		input.Update(scene);
		movement.Update(scene);
		renderer.Update(scene);

		window.Update();
	};
}