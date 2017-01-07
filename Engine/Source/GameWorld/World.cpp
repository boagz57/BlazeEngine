#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "Universal/Globals.h"
#include "Input/Keyboard/Keyboard.h"
#include "Entity.h"
#include "Graphics/Graphics.h"
#include "Triangle.h"
#include "World.h"

World::World() : mNumberOfEntities(0)
{
}

void World::GameLoop()
{
	BlazeFramework::OpenGL::RestartGLLogFile();
	BlazeFramework::OpenGL::LogToFile("starting GLFW\n%s\n", glfwGetVersionString());
	Triangle triangle;
	Graphics graphics(&triangle);

	graphics.InitializeBuffers();
	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	BlazeInput::Keyboard keyboard;

	for (int i = 0; i < 1; i++)
	{
		mEntities.push_back(&triangle);
		mNumberOfEntities++;
	}

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		uint16 numberOfEntitiesThisFrame = mNumberOfEntities;
		for (int i = 0; i < numberOfEntitiesThisFrame; i++)
		{
			mEntities.at(i)->Update();
		}

		graphics.Draw();

		window.Update();
	};
}