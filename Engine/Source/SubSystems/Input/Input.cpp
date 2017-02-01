#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GameWorld/GameEntities/Entity/Entity.h"
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
		return true;
	}

	bool Input::Shutdown()
	{
		return true;
	}

	void Input::BindKey(const uint16 key, void(*keyHandlerFunc)())
	{
		keyMap[key] = keyHandlerFunc;
	}

	void Input::UseInput()
	{
		if (BlazeFramework::KeyboardHandling::PollInput() == 349)
			return;

		keyMap.at(BlazeFramework::KeyboardHandling::PollInput())();
	}

}
