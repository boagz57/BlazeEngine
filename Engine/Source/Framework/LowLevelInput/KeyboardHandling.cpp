#include "Precompiled.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "KeyboardHandling.h"

namespace BlazeFramework
{
	//Not part of KeyboardHandling class (Callback functions cannot be class members).
	//Only serves as a callback function to be used within SetWindowContextForKeyboard().
	//Is used to set the boolean at the keycode location (in the array) to true if the 
	//key is pressed. This key state will then be polled each frame.
	void KeyCallBackFunction(WindowHandling::BlazeWindow* window, int keyCode, int scancode, int action, int mods)
	{
		KeyboardHandling::mKeyCodes.at(keyCode) = (action != GLFW_RELEASE);
	}
	
	KeyboardHandling::KeyboardHandling()
	{
		for (auto& keyCode : mKeyCodes)
		{
			keyCode = false;
		}
	}

	//Will specify what window you want to poll your KeyCallBackFunction from every frame.
	void KeyboardHandling::SetWindowContextForKeyboard(WindowHandling::BlazeWindow * window)
	{
		glfwSetKeyCallback(window, KeyCallBackFunction);
	}

	//This is used to extract out what key has actually been pressed from glfw so that 
	//you can use this information to perform whatever action you attach to this input.
	bool KeyboardHandling::IsKeyPressed(const uint16 key)
	{
		RUNTIME_ASSERT(key <= GLFW_KEY_LAST, "ERROR: keycode entered does not exist on keyboard");

		return KeyboardHandling::mKeyCodes.at(key);
	}

	Array<bool, GLFW_KEY_LAST> KeyboardHandling::mKeyCodes;
}