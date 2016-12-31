#pragma once
#include "Macro.h"
//Needs to be included before the glfw.h (since RenderWindow contains glew.h)
#include "../LowLevelWindow/WindowHandling.h"
#include "../Array/Array.h"
#include "GLFW/glfw3.h"

namespace BlazeFramework
{
	enum Key
	{
		RightArrow = GLFW_KEY_RIGHT,
		LeftArrow = GLFW_KEY_LEFT,
		UpArrow = GLFW_KEY_UP,
		DownArrow = GLFW_KEY_DOWN,
		SpaceBar = GLFW_KEY_SPACE,
	};

	class KeyboardHandling
	{
	public:
		KeyboardHandling();

		static void SetWindowContextForKeyboard(WindowHandling::BlazeWindow* window);
		static bool IsKeyPressed(const uint16 key);

	private:
		friend void KeyCallBackFunction(WindowHandling::BlazeWindow* window, int keyCode, int scancode, int action, int mods);
		static BlazeFramework::Array<bool, GLFW_KEY_LAST> m_keyCodes;
	};
}