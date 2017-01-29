#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Graphics.h"
#include "Physics/Physics.h"
#include "Input/Input.h"
#include "Entity.h"

namespace BlazeGameWorld
{
	Entity::Entity() : renderer(std::make_unique<BlazeGraphics::Graphics>()),
		input(std::make_unique<BlazeInput::Input>()),
		physics(std::make_unique<BlazePhysics::Physics>()),
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
