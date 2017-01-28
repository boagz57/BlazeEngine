#include "Precompiled.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "KeyboardHandling.h"

namespace BlazeFramework
{
	//I've implemented the call back function this way so that input will be truly polled each frame,
	//regardless if the key is held down or not. Without this implementation, holding down a key will
	//cause a slight delay for the action for the first few frames.
	void KeyCallBackFunction(WindowHandling::BlazeWindow* window, int keyCode, int scancode, int action, int mods)
	{
		KeyboardHandling::KeyCodes.at(keyCode) = (action != GLFW_RELEASE);
	}
	
	KeyboardHandling::KeyboardHandling()
	{
		for (auto& keyCode : KeyCodes)
		{
			keyCode = false;
		}
	}

	//Will specify what window you want to poll your KeyCallBackFunction from every frame.
	//The glfw KeyCallBack function is only used inside this function.
	void KeyboardHandling::SetWindowContextForKeyboard(WindowHandling::BlazeWindow * window)
	{
		glfwSetKeyCallback(window, KeyCallBackFunction);
	}

	//This is used to extract out what key has actually been pressed from glfw so that 
	//you can use this information to perform whatever action is associated with what key is returned.
	uint16 KeyboardHandling::PollInput()
	{
		if (KeyboardHandling::KeyCodes.at(GLFW_KEY_RIGHT))
			return GLFW_KEY_RIGHT;
		else if (KeyboardHandling::KeyCodes.at(GLFW_KEY_LEFT))
			return GLFW_KEY_LEFT;
		else if (KeyboardHandling::KeyCodes.at(GLFW_KEY_UP))
			return GLFW_KEY_UP;
		else if (KeyboardHandling::KeyCodes.at(GLFW_KEY_DOWN))
			return GLFW_KEY_DOWN;
		else
			//This final else statement gets rid of a compiler warning saying not all control paths
			//return a value. Returning -1 since no glfw keys are mapped to -1.
			return -1;
	}

	Array<bool, GLFW_KEY_LAST> KeyboardHandling::KeyCodes;
}