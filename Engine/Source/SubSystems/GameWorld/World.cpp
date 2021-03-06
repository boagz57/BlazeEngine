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
	BPhysics::MovementSystem movement;
	BInput::InputSystem input;
	BPhysics::CollisionSystem collision;
	BGraphics::RenderSystem renderer;

	SceneManager scene;
	scene.Initialize();
	scene.CreatePlayer(BlazeFramework::Vector3D(0.0f, 0.0f, 0.0f), "Triangle");
	scene.CreateStaticEntity(BlazeFramework::Vector3D(0.0f, 0.4f, 0.0f), "Square");
	scene.CreateStaticEntity(BlazeFramework::Vector3D(0.4f, 0.4f, 0.0f), "Triangle");

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