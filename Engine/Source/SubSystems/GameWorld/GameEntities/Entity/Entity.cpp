#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Graphics.h"
#include "Input/Controller.h"
#include "Physics/Physics.h"
#include "Input/Input.h"
#include "Entity.h"

namespace BlazeGameWorld
{
	Entity::Entity(BlazeGraphics::Graphics* renderer, BlazeInput::Input* input, BlazePhysics::Physics* physics, BlazeInput::Controller* controller) :
		renderer(renderer),
		input(input),
		physics(physics),
		controller(controller),
		position(0.0f, 0.0f),
		velocity(0.0f, 0.0f)
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::AnotherFunc()
	{

	}
}
