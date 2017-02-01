#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GameWorld/GameEntities/Entity/Entity.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "GLFW/glfw3.h"
#include "Universal/Globals.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "Input.h"

//This function is only used for initializing the keyMap member to default functions. Read 
//more below.
void DoNothing()//TODO: This is a hack and must be fixed and removed at some point
{};

namespace BlazeInput
{
	Input::Input()
	{}

	Input::~Input()
	{}

	bool Input::Initialize()
	{
		BlazeFramework::KeyboardHandling::SetWindowContextForKeyboard(window.m_window);

		//Instantiating enough values in keyMap to make sure to cover all possible keys on the 
		//keyboard. By providing a default function to point to that does nothing to all keys 
		//I can prevent crashes from occuring from keys which are not explicitly bound in the 
		//Bind function. 
		for (int i = 0; i < (BlazeFramework::Key::MaxKey + 2); i++)//TODO: This is currently a hack and implementation must be fixed.
		{
			movementKeyBindings[i] = DoNothing;
		}

		return true;
	}

	bool Input::Shutdown()
	{
		return true;
	}

	void Input::BindMovement(const uint16 key, void(*pointerToMovementFunc)())
	{
		movementKeyBindings[key] = pointerToMovementFunc;
	}

	void Input::Update()
	{
		//Calls the function being stored at whatever keyCode location in the map data structure.
		movementKeyBindings.at(BlazeFramework::KeyboardHandling::PollInput())();
	}
}
