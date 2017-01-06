#include "Precompiled.h"
#include "../Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "../Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "../Universal/Globals.h"
#include "../Input/Keyboard/Keyboard.h"
#include "Entity.h"
#include "../Graphics/Graphics.h"
#include "World.h"

World::World()
{
}

void World::GameLoop()
{
	BlazeFramework::OpenGL::RestartGLLogFile();
	BlazeFramework::OpenGL::LogToFile("starting GLFW\n%s\n", glfwGetVersionString());
	Entity Triangle;
	Graphics graphics(&Triangle);

	graphics.InitializeBuffers();
	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	BlazeInput::Keyboard keyboard;

	while (!window.Closed())
	{
		window.Clear();

		engineClock.NewFrame();

		graphics.Draw();

		window.Update();
	};
}