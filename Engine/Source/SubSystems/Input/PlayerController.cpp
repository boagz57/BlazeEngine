#include "Precompiled.h"
#include "Universal/Macro.h"
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

		input.BindMovement(BlazeFramework::Key::UpArrow, Controller::MoveUp);
		input.BindMovement(BlazeFramework::Key::DownArrow, Controller::MoveDown);
		input.BindMovement(BlazeFramework::Key::LeftArrow, Controller::MoveLeft);
		input.BindMovement(BlazeFramework::Key::RightArrow, Controller::MoveRight);

		return false;
	}

	bool PlayerController::Shutdown()
	{
		return false;
	}

	void PlayerController::Update(BlazeGameWorld::Entity& entity)
	{
		input.Update();
	}
}
