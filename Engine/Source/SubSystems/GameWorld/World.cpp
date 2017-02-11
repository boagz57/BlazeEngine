#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Universal/Globals.h"
#include "GameWorld/Entity.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"
#include "InputComponents/KeyboardComponent/KeyboardComponent.h"
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
	BlazeGameWorld::Entity* enemyTriangle = sceneManager.CreateEntity();

	triangle->AddComponent(new BlazeGraphics::RendererComponent);
	enemyTriangle->AddComponent(new BlazeGraphics::RendererComponent);

	triangle->Initialize(BlazeFramework::Math::Vector2D(0.0f, 0.0f));
	enemyTriangle->Initialize(BlazeFramework::Math::Vector2D(0.0f, 0.4f));

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