#include "Precompiled.h"
#include <memory.h>
#include "Graphics/Graphics.h"
#include "Entity.h"


Entity::Entity() : velocity(0), graphics(std::make_unique<Graphics>())
{
}

Entity::~Entity()
{
}

void Entity::AnotherFunc()
{

}
