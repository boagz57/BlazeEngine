#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "Universal/Globals.h"
#include "Input/Keyboard/Keyboard.h"
#include "Ship.h"
#include "Audio/Audio.h"
#include "Graphics/Graphics.h"
#include "World.h"

World::World() : mNumberOfEntities(0)
{
}

World::~World()
{

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

	mEntities.push_back(&triangle);
	mNumberOfEntities++;

	mEntities.push_back(&triangle2);
	mNumberOfEntities++;

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		uint16 numberOfEntitiesThisFrame = mNumberOfEntities;
		for (int i = 0; i < numberOfEntitiesThisFrame; i++)
		{
			mEntities.at(i)->Update();
		}

		window.Update();
	};
}