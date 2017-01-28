#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "GLFW/glfw3.h"
#include "Universal/Globals.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "Input.h"

namespace BlazeInput
{
	Input::Input()
	{}

	Input::~Input()
	{}

	bool Input::Initialize()
	{
		BlazeFramework::KeyboardHandling::SetWindowContextForKeyboard(window.m_window);
		return false;
	}

	bool Input::Shutdown()
	{
		return false;
	}

	void Input::KeyPress()
	{
		switch (BlazeFramework::KeyboardHandling::PollInput())
		{
			case GLFW_KEY_RIGHT: LOG("INput pressed");
				break;

			case GLFW_KEY_LEFT: LOG("kkek");
				break;

			default:
				break;
		}
	}

}
