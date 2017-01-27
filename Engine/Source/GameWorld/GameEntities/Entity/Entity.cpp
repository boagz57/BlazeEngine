#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Graphics.h"
#include "Entity.h"


Entity::Entity() : graphics(std::make_unique<Graphics>()), 
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
