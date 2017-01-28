#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Renderer.h"
#include "Input/Input.h"
#include "Entity.h"


Entity::Entity() : graphics(std::make_unique<BlazeGraphics::Renderer>()), 
	input(std::make_unique<BlazeInput::Input>()),
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
