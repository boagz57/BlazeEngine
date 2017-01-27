#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "Universal/Globals.h"
#include "Input/Keyboard/Keyboard.h"
#include "GameWorld/GameEntities/Ship.h"
#include "Audio/Audio.h"
#include "Graphics/Graphics.h"
#include "World.h"

World::World() : numEntities(0)
{}

World::~World()
{}

bool World::Initialize()
{
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
	triangle2.Initialize(.6f);
	triangle.Initialize(-.6f);

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	BlazeInput::Keyboard keyboard;

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