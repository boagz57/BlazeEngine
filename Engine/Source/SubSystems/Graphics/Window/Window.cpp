#include "Precompiled.h"
#include "Universal/UniversalTypeDefs.h"
#include "../../../Framework/LowLevelGraphics/OpenGL/Initialization/GLInitialization.h"
#include "../Universal/Globals.h"
#include "Window.h"

namespace BGraphics
{
	Window::Window(uint16 width, uint16 height, char8* title) :
		cWidth(width),
		cHeight(height),
		cpTitle(title)
	{
		BlazeFramework::OpenGL::InitializeGLFW();

		//InitializeWindow
		{
			m_window = BlazeFramework::WindowHandling::CreateWindow(cWidth, cHeight, cpTitle, NULL, NULL);

			if (!m_window)
			{
				LOG("Failed to initialize window!");
				BlazeFramework::WindowHandling::TerminateWindowContextAndGLFW();
				return;
			};

			//Making this window the current context must happen before glew can be initialized!!!
			BlazeFramework::WindowHandling::MakeCurrentRenderContext(m_window);
			BlazeFramework::WindowHandling::CenterViewportToWindow(m_window);
		}

		BlazeFramework::OpenGL::InitializeGlew();
		BlazeFramework::OpenGL::SetMinGLVersion();
	}


	Window::~Window()
	{
		BlazeFramework::WindowHandling::TerminateWindowContextAndGLFW();
	}

	void Window::Update()
	{
		BlazeFramework::WindowHandling::PollEvents();
		BlazeFramework::WindowHandling::SwapFrontAndBackBuffers(m_window);
	}

	void Window::Clear() const
	{
		BlazeFramework::WindowHandling::ClearColorAndDepthBuffers();
	}

	//Returns a bool because CloseWindow returns a nonzero number or zero
	bool Window::Closed() const
	{
		//Made it equal to 1 to take away warning involving converting an int to bool
		return BlazeFramework::WindowHandling::CloseWindow(m_window) == 1;
	}
}

//Global object declaration/intialization. Can be found in Globals.h
BGraphics::Window window(1280, 720, "Render Window");