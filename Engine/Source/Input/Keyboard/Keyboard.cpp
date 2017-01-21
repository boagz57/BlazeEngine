#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "GLFW/glfw3.h"
#include "Universal/Globals.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "Keyboard.h"

namespace BlazeInput
{
	void Keyboard::ReadInput()
	{
		using namespace BlazeFramework;

		if (KeyboardHandling::IsKeyPressed(Key::RightArrow))
			MyOpenGL::MoveTriangle(.6f, 0.0f);
		else if (KeyboardHandling::IsKeyPressed(Key::LeftArrow))
			MyOpenGL::MoveTriangle(-.6f, 0.0f);
		else if (KeyboardHandling::IsKeyPressed(Key::UpArrow))
			MyOpenGL::MoveTriangle(0.0f, 0.6f);
		else if (KeyboardHandling::IsKeyPressed(Key::DownArrow))
			MyOpenGL::MoveTriangle(0.0f, -0.6f);
	}

	bool Keyboard::KeyPress(const uint16 key)
	{
		BlazeFramework::KeyboardHandling::SetWindowContextForKeyboard(window.m_window);
		return BlazeFramework::KeyboardHandling::IsKeyPressed(key);
	}

}
