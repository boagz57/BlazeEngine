#include "Precompiled.h"
#include "../Framework/MyOpenGL.h"
#include "../Universal/Globals.h"
#include "../Input/Keyboard/Keyboard.h"
#include "World.h"

World::World()
{
}

void World::GameLoop()
{
	MyOpenGL::RestartGLLogFile();
	MyOpenGL::GlLogToFile("starting GLFW\n%s\n", glfwGetVersionString());

	MyOpenGL::InitializeGLBuffers();
	MyOpenGL::InstallShaders();
	MyOpenGL::Initialize();

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