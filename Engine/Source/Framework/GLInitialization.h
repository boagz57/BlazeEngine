#pragma once
#include "Macro.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace BlazeFramework
{
	namespace GLInitialization
	{
		inline void InitializeGLFW()
		{
			if (!glfwInit())
			{
				LOG("Failed to initialize glfw!");
				return;
			};
		}

		inline void InitializeGLEW()
		{
			if (glewInit() != GLEW_OK)
			{
				LOG("Failed to initialize glew!");
			};
		}

		inline void SetMinGLVersion()
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		}
	};
}