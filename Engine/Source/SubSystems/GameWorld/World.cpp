#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "Universal/Globals.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "Math/Vector2D/Vector2D.h"
#include "Physics/PhysicsManager.h"
#include "GameWorld/NPC.h"
#include "Input/InputManager.h"
#include "GameWorld/Player.h"
#include "Audio/Audio.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "World.h"

World::World()
{}

World::~World()
{}

bool World::Initialize()
{
	numEntities = 0;
	return true;
}

bool World::Shutdown()
{
	return true;
}

void World::GameLoop()
{
	BlazePhysics::PhysicsManager physics;
	physics.Initialize();

	BlazeGameWorld::Player triangle;
	BlazeGameWorld::NPC EnemyTriangle;

	triangle.Initialize(BlazeFramework::Math::Vector2D(0.0f, 0.0f), BlazeGraphics::ShapeData::Triangle());
	EnemyTriangle.Initialize(BlazeFramework::Math::Vector2D(0.0f, 0.5f), BlazeGraphics::ShapeData::Triangle());

	physics.AddPhysicsComponent(triangle.GetPhysicsComponent());
	physics.AddPhysicsComponent(EnemyTriangle.GetPhysicsComponent());

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	entities.push_back(&triangle);
	numEntities++;

	entities.push_back(&EnemyTriangle);
	numEntities++;

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		uint16 numberOfEntitiesThisFrame = numEntities;
		for (int i = 0; i < numberOfEntitiesThisFrame; i++)
		{
			entities.at(i)->Update();
		}

		physics.Update();

		window.Update();
	};
}