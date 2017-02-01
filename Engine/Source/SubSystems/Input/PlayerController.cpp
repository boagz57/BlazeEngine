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

		input.BindKey(BlazeFramework::Key::UpArrow, Controller::MoveUp);
		input.BindKey(BlazeFramework::Key::DownArrow, Controller::MoveDown);
		input.BindKey(BlazeFramework::Key::LeftArrow, Controller::MoveLeft);
		input.BindKey(BlazeFramework::Key::RightArrow, Controller::MoveRight);

		return false;
	}

	bool PlayerController::Shutdown()
	{
		return false;
	}

	void PlayerController::Update(BlazeGameWorld::Entity& entity)
	{
		input.UseInput();
	}
}
