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

	void Input::Update(BlazeGameWorld::Entity& entity)
	{
		switch (BlazeFramework::KeyboardHandling::PollInput())
		{
			case BlazeFramework::Key::RightArrow:
				entity.velocity.x = .6f;
				break;
			case BlazeFramework::Key::LeftArrow: 
				entity.velocity.x = -.6f;
				break;
			case BlazeFramework::Key::UpArrow: 
				entity.velocity.y = .6f;
				break;
			case BlazeFramework::Key::DownArrow: 
				entity.velocity.y = -.6f;
				break;
			default:
				break;
		}
	}
}
