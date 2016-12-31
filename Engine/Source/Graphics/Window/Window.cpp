#include "Precompiled.h"
#include "UniversalTypeDefs.h"
#include "../Framework/GLInitialization.h"
#include "../Universal/Globals.h"
#include "Window.h"

namespace BlazeGraphics
{
	Window::Window(uint16 width, uint16 height, char8* title) :
		M_WIDTH(width),
		M_HEIGHT(height),
		M_TITLE(title)
	{
		BlazeFramework::GLInitialization::InitializeGLFW();

		//InitializeWindow
		{
			m_window = BlazeFramework::WindowHandling::CreateWindow(M_WIDTH, M_HEIGHT, M_TITLE, NULL, NULL);

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

		BlazeFramework::GLInitialization::InitializeGLEW();
		BlazeFramework::GLInitialization::SetMinGLVersion();
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
BlazeGraphics::Window window(1280, 720, "Render Window");