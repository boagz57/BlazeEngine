#pragma once
#include "Universal\UniversalTypeDefs.h"
#include "GLFW\glfw3.h"

namespace BlazeFramework
{
	namespace WindowHandling
	{
		typedef GLFWwindow BlazeWindow;
		typedef GLFWmonitor BlazeMonitor;

		void MakeCurrentRenderContext(BlazeWindow* p_window);
		void TerminateWindowContextAndGLFW();
		void SwapFrontAndBackBuffers(BlazeWindow* p_window);
		void ClearColorAndDepthBuffers();

		uint16 CloseWindow(BlazeWindow* window);
		void PollEvents();
		BlazeWindow* CreateWindow(uint16 width, uint16 height, const char8* title, BlazeMonitor* monitor, BlazeWindow* share);

		//Created only to be used as a callback function to CenterVeiwportToWindow
		//which just uses glfw callback function (glfwSetWindowSizeCallback) to resize veiwport properly.
		void ViewportResize(BlazeWindow* window, int width, int height);
		void CenterViewportToWindow(BlazeWindow* window);
	}
}
