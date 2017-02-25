#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "Universal/Globals.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "InputSystem.h"

static Velocity* entityVelocity = nullptr;

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
	return true;
}

bool InputSystem::Shutdown()
{
	return true;
}

void InputSystem::Update(SceneManager& scene)
{
	//Loop through all 'entities' in scene to see which entities match the
	//system bit mask (which entity 'keys' fit into the system 'lock').
	for (uint16 entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & INPUT_MASK) == INPUT_MASK)
		{
			entityVelocity = &scene.velocityComponents.at(entity);

			//Calls the function being stored at whatever keyCode location is polled
			switch (BlazeFramework::KeyboardHandling::PollInput())
			{
			case BlazeFramework::Key::W :
				entityVelocity->SetVelocityY(.6f);
				break;
			case BlazeFramework::Key::S :
				entityVelocity->SetVelocityY(-.6f);
				break;
			case BlazeFramework::Key::D :
				entityVelocity->SetVelocityX(.6f);
				break;
			case BlazeFramework::Key::A :
				entityVelocity->SetVelocityX(-.6f);
				break;
			default:
				break;
			}
		}
	}
}
