#include "Precompiled.h"
#include "UniversalTypeDefs.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "WindowHandling.h"

namespace BlazeFramework
{
	namespace WindowHandling
	{
		typedef GLFWwindow BlazeWindow;
		typedef GLFWmonitor BlazeMonitor;

		void MakeCurrentRenderContext(BlazeWindow* window)
		{
			glfwMakeContextCurrent(window);
		}

		void TerminateWindowContextAndGLFW()
		{
			glfwTerminate();
		}

		void SwapFrontAndBackBuffers(BlazeWindow* window)
		{
			glfwSwapBuffers(window);
		}

		void ClearColorAndDepthBuffers()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		int CloseWindow(BlazeWindow* window)
		{
			return glfwWindowShouldClose(window);
		}

		void PollEvents()
		{
			glfwPollEvents();
		}

		BlazeWindow* CreateWindow(int width, int height, const char8* title, BlazeMonitor* monitor, BlazeWindow* share)
		{
			return glfwCreateWindow(width, height, title, monitor, share);
		}

		//Created only to be used as a callback function to CenterVeiwportToWindow
		//which just uses glfw callback function (glfwSetWindowSizeCallback) to resize veiwport properly.
		void ViewportResize(BlazeWindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void CenterViewportToWindow(BlazeWindow* window)
		{
			glfwSetWindowSizeCallback(window, ViewportResize);
		}
	}
}
