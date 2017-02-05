#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GameWorld/Entity.h"
#include "GameWorld/Pawn.h"
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
			p_entity->velocity.y = .6f;
			break;

		case BlazeFramework::Key::DownArrow:
			p_entity->velocity.y = -.6f;
			break;

		case BlazeFramework::Key::RightArrow:
			p_entity->velocity.x = .6f;
			break;

		case BlazeFramework::Key::LeftArrow:
			p_entity->velocity.x = -.6f;
			break;

		default:
			break;
		}
	}
}