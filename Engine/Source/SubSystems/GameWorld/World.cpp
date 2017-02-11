#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Universal/Globals.h"
#include "GameWorld/Entity.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"
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
	SceneManager sceneManager;

	BlazeGameWorld::Entity* triangle = sceneManager.CreateEntity();
	triangle->AddComponent(new BlazeGraphics::RendererComponent);

	triangle->Initialize(BlazeFramework::Math::Vector2D(0.0f, 0.0f));

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		sceneManager.Update();

		window.Update();
	};
}