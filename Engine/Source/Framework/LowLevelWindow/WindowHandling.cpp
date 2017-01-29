#include "Precompiled.h"
#include "Universal\Macro.h"
#include "Universal\UniversalTypeDefs.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "WindowHandling.h"

namespace BlazeFramework
{
	namespace WindowHandling
	{
		typedef GLFWwindow BlazeWindow;
		typedef GLFWmonitor BlazeMonitor;

		void MakeCurrentRenderContext(BlazeWindow* p_window)
		{
			RUNTIME_ASSERT(p_window != nullptr, "ERROR: No window to set current context!");
			glfwMakeContextCurrent(p_window);
		}

		void TerminateWindowContextAndGLFW()
		{
			glfwTerminate();
		}

		void SwapFrontAndBackBuffers(BlazeWindow* p_window)
		{
			RUNTIME_ASSERT(p_window != nullptr, "ERROR: No window context to swap buffers!");
			glfwSwapBuffers(p_window);
		}

		void ClearColorAndDepthBuffers()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		uint16 CloseWindow(BlazeWindow* p_window)
		{
			RUNTIME_ASSERT(p_window != nullptr, "ERROR: No window to close!");
			return glfwWindowShouldClose(p_window);
		}

		void PollEvents()
		{
			glfwPollEvents();
		}

		BlazeWindow* CreateWindow(uint16 width, uint16 height, const char8* p_title, BlazeMonitor* p_monitor, BlazeWindow* p_share)
		{
			return glfwCreateWindow(width, height, p_title, p_monitor, p_share);
		}

		//Created only to be used as a callback function to CenterVeiwportToWindow
		//which just uses glfw callback function (glfwSetWindowSizeCallback) to resize veiwport properly.
		void ViewportResize(BlazeWindow* p_window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void CenterViewportToWindow(BlazeWindow* p_window)
		{
			glfwSetWindowSizeCallback(p_window, ViewportResize);
		}
	}
}
