#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Controller.h"

namespace BlazeInput
{
	Controller::Controller()
	{
	}


	Controller::~Controller()
	{
	}

	void Controller::MoveUp()
	{
		LOG("Up");
	}

	void Controller::MoveDown()
	{
		LOG("Down");
	}

	void Controller::MoveLeft()
	{
		LOG("Left");
	}

	void Controller::MoveRight()
	{
		LOG("Right");
	}

}
