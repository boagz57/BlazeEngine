#include "Precompiled.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "GLFW/glfw3.h"
#include "Universal/Globals.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "Keyboard.h"

namespace BlazeInput
{
	bool Keyboard::KeyPress(const uint16 cKey)
	{
		BlazeFramework::KeyboardHandling::SetWindowContextForKeyboard(window.m_window);
		return BlazeFramework::KeyboardHandling::IsKeyPressed(cKey);
	}

}
