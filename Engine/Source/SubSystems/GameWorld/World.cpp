#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "Universal/Globals.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "Math/Vector2D/Vector2D.h"
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
	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		uint16 numberOfEntitiesThisFrame = numEntities;
		for (int i = 0; i < numberOfEntitiesThisFrame; i++)
		{
			entities.at(i)->Update();
		}

		window.Update();
	};
}