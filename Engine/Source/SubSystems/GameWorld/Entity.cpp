#include "Precompiled.h"
#include "Macro.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include "SubSystems/Component.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "Entity.h"

namespace BlazeGameWorld
{
	Entity::Entity(uint16 entityID) :
		entityID(entityID)
	{
	}

	Entity::~Entity()
	{}

	bool Entity::Initialize(BlazeFramework::Math::Vector2D startPosition)
	{
		return true;
	}

	bool Entity::Shutdown()
	{
		return true;
	}

	void Entity::Update()
	{
	}
}
