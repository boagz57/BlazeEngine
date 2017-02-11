#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GameWorld/Entity.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "GLFW/glfw3.h"
#include "Universal/Globals.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "KeyboardComponent.h"

namespace BlazeInput
{
	KeyboardComponent::KeyboardComponent()
	{}

	KeyboardComponent::~KeyboardComponent()
	{}

	bool KeyboardComponent::Initialize(BlazeGameWorld::Entity* p_entity)
	{
		BlazeFramework::KeyboardHandling::SetWindowContextForKeyboard(window.m_window);
		this->p_entity = p_entity;

		return true;
	}

	bool KeyboardComponent::Shutdown()
	{
		return true;
	}

	void KeyboardComponent::Update()
	{
		//Calls the function being stored at whatever keyCode location is polled
		switch (BlazeFramework::KeyboardHandling::PollInput())
		{
		case BlazeFramework::Key::UpArrow:
			break;

		case BlazeFramework::Key::DownArrow:
			break;

		case BlazeFramework::Key::RightArrow:
			break;

		case BlazeFramework::Key::LeftArrow:
			break;

		default:
			break;
		}
	}
}