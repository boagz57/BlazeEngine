#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Graphics.h"
#include "Input/Controller.h"
#include "Physics/Physics.h"
#include "Input/Input.h"
#include "Entity.h"

namespace BlazeGameWorld
{
	Entity::Entity()
	{}

	Entity::Entity(BlazeGraphics::Graphics* renderer, BlazePhysics::Physics* physics, BlazeInput::Controller* controller) :
		renderer(renderer),
		physics(physics),
		controller(controller),
		position(0.0f, 0.0f),
		velocity(0.0f, 0.0f)
	{
	}

	Entity::~Entity()
	{
	}
}
