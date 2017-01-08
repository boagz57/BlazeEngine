#include "Precompiled.h"
#include <memory>
#include "Graphics/Graphics.h"
#include "Entity.h"


Entity::Entity() : velocity(0)
{
	graphics = new Graphics;
}

Entity::~Entity()
{
	delete graphics;
	graphics = nullptr;
}

void Entity::Initialize()
{
	graphics->InitializeBuffers();
}

void Entity::Update()
{
	graphics->Update(*this);
}
