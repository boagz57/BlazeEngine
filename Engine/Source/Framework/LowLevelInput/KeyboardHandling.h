#pragma once
#include "Universal/Macro.h"
//Needs to be included before the glfw.h (since RenderWindow contains glew.h)
#include "LowLevelWindow/WindowHandling.h"
#include "DataStructures/Array.h"
#include "GLFW/glfw3.h"

namespace BlazeFramework
{
	enum Key
	{
		RightArrow = GLFW_KEY_RIGHT,
		LeftArrow = GLFW_KEY_LEFT,
		DownArrow = GLFW_KEY_DOWN,
		UpArrow = GLFW_KEY_UP,
		W = GLFW_KEY_W,
		A = GLFW_KEY_A,
		S = GLFW_KEY_S,
		D = GLFW_KEY_D,
		I = GLFW_KEY_I,
		J = GLFW_KEY_J,
		K = GLFW_KEY_K,
		L = GLFW_KEY_L,
		MaxKey = GLFW_KEY_LAST
	};

	class KeyboardHandling
	{
	public:
		KeyboardHandling();

		static void SetWindowContextForKeyboard(WindowHandling::BlazeWindow* window);
		static uint16 PollInput();

	private:
		friend void KeyCallBackFunction(WindowHandling::BlazeWindow* window, int keyCode, int scancode, int action, int mods);
		//This boolean array will be used to set different keycodes to either true 
		//or false, depending on what keys have been pressed
		static Array<bool, GLFW_KEY_LAST> KeyCodes;
	};
}