#include "Precompiled.h"
#include "Input/InputSystem.h"
#include "Graphics/RenderSystem.h"
#include "Physics/MovementSystem.h"
#include "Physics/CollisionSystem.h"
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
	CollisionSystem collision;
	BlazeGraphics::RenderSystem renderer;

	SceneManager scene;

	scene.Initialize();

	//Player
	scene.CreatePlayer(BlazeFramework::Vector2D(0.0f, 0.0f), "Triangle");
	//Scenery
	scene.CreateStaticEntity(BlazeFramework::Vector2D(0.0f, 0.4f), "Square");

	input.Initialize();
	movement.Initialize();
	collision.Initialize(scene);
	renderer.Initialize(scene);

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		input.Update(scene);
		movement.Update(scene);
		collision.Update(scene);
		renderer.Update(scene);

		window.Update();
	};
}