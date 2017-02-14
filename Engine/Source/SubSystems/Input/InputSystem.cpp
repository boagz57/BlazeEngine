#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "Universal/Globals.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "InputSystem.h"

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

bool InputSystem::Initialize()
{
	//InputSystem is a friend of Window so it has access to Windows private
	//member window.
	BlazeFramework::KeyboardHandling::SetWindowContextForKeyboard(window.m_window);
	return false;
}

bool InputSystem::Shutdown()
{
	return false;
}

void InputSystem::Update(SceneManager& scene)
{
	uint16 entity = 0;

	//Loop through all 'entities' in scene to see which entities match the
	//render bit mask (which entity 'keys' fit into the render 'lock').
	for (entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & INPUT_MASK) == INPUT_MASK)
		{
			VelocityComponent* entityVelocity = &scene.velocityComponents.at(entity);

			//Calls the function being stored at whatever keyCode location is polled
			switch (BlazeFramework::KeyboardHandling::PollInput())
			{
			case BlazeFramework::Key::UpArrow:
				entityVelocity->velocity.y += .6f;
				break;
			case BlazeFramework::Key::DownArrow:
				entityVelocity->velocity.y += -.6f;
				break;
			case BlazeFramework::Key::RightArrow:
				entityVelocity->velocity.x += .6f;
				break;
			case BlazeFramework::Key::LeftArrow:
				entityVelocity->velocity.x += -.6f;
				break;
			default:
				break;
			}
		}
	}
}
