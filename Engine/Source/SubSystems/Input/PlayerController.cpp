#include "Precompiled.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "Input/Input.h"
#include "PlayerController.h"

namespace BlazeInput
{
	PlayerController::PlayerController()
	{
	}

	PlayerController::~PlayerController()
	{
	}

	bool PlayerController::Initialize()
	{
		input.Initialize();
		return false;
	}

	bool PlayerController::Shutdown()
	{
		return false;
	}

	void PlayerController::Update(BlazeGameWorld::Entity& entity)
	{
		switch (BlazeFramework::KeyboardHandling::PollInput())
		{
		case BlazeFramework::Key::RightArrow:
			entity.velocity.x = .6f;
			break;
		case BlazeFramework::Key::LeftArrow:
			entity.velocity.x = -.6f;
			break;
		case BlazeFramework::Key::UpArrow:
			entity.velocity.y = .6f;
			break;
		case BlazeFramework::Key::DownArrow:
			entity.velocity.y = -.6f;
			break;
		default:
			break;
		}
	}

}
