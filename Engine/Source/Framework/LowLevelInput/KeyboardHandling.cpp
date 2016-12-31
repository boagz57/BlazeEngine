#include "Precompiled.h"
#include "../MyOpenGL.h"
#include "KeyboardHandling.h"

namespace BlazeFramework
{
	//Not part of KeyboardHandling class (Callback functions cannot be class members)
	//Only serves as a callback function to be used within SetWindowContextForKeyboard()
	void KeyCallBackFunction(WindowHandling::BlazeWindow* window, int keyCode, int scancode, int action, int mods)
	{
		KeyboardHandling::m_keyCodes.at(keyCode) = (action != GLFW_RELEASE);
	}
	
	KeyboardHandling::KeyboardHandling()
	{
		for (auto& keyCode : m_keyCodes)
		{
			keyCode = false;
		}
	}

	void KeyboardHandling::SetWindowContextForKeyboard(WindowHandling::BlazeWindow * window)
	{
		glfwSetKeyCallback(window, KeyCallBackFunction);
	}

	bool KeyboardHandling::IsKeyPressed(const uint16 key)
	{
		RUNTIME_ASSERT(key <= GLFW_KEY_LAST, "ERROR: keycode entered does not exist on keyboard");

		return KeyboardHandling::m_keyCodes.at(key);
	}

	BlazeFramework::Array<bool, GLFW_KEY_LAST> KeyboardHandling::m_keyCodes;
}