#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Renderer.h"
#include "Entity.h"


Entity::Entity() : graphics(std::make_unique<BlazeGraphics::Renderer>()), 
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
