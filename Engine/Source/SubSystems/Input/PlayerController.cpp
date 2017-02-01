#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "Input/Input.h"
#include "PlayerController.h"

void Func();

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
		input.BindKey(BlazeFramework::Key::UpArrow, Func);

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

	void PlayerController::MoveForward(sfloat velocity)
	{

	}

}

void Func()
{
	LOG("Hello");
}
