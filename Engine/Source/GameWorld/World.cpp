#include "Precompiled.h"
#include "../Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "../Framework/LowLevelGraphics/OpenGL/ErrorLogging/ErrorLogging.h"
#include "../Universal/Globals.h"
#include "../Input/Keyboard/Keyboard.h"
#include "World.h"

World::World()
{
}

void World::GameLoop()
{
	BlazeFramework::OpenGL::RestartGLLogFile();
	BlazeFramework::OpenGL::LogToFile("starting GLFW\n%s\n", glfwGetVersionString());

	MyOpenGL::InitializeGLBuffers();
	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	BlazeInput::Keyboard keyboard;

	while (!window.Closed())
	{
		window.Clear();

		engineClock.NewFrame();
		keyboard.ReadInput();

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

		window.Update();
	};
}