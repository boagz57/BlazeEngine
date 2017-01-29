#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "Universal/Globals.h"
#include "Math/Vector2D/Vector2D.h"
#include "Input/Input.h"
#include "GameWorld/GameEntities/Ship.h"
#include "Audio/Audio.h"
#include "Graphics/Graphics.h"
#include "World.h"

World::World()
{}

World::~World()
{}

bool World::Initialize()
{
	numEntities = 0;
	return false;
}

bool World::Shutdown()
{
	return false;
}

void World::GameLoop()
{
	BlazeFramework::OpenGL::RestartGLLogFile();
	BlazeFramework::OpenGL::LogToFile("starting GLFW\n%s\n", glfwGetVersionString());

	Ship triangle;
	Ship triangle2;
	triangle2.Initialize(BlazeFramework::Math::Vector2D(0.0f, 0.5f));
	triangle.Initialize(BlazeFramework::Math::Vector2D(0.0f, 0.0f));

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	entities.push_back(&triangle);
	numEntities++;

	entities.push_back(&triangle2);
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

		window.Update();
	};
}