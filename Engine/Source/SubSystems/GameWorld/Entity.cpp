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
		entityID(entityID),
		numComponents(0),
		numMaxComponents(10),
		position(0.0f, 0.0f)
	{
		components.reserve(numMaxComponents);
	}

	Entity::~Entity()
	{}

	bool Entity::Initialize(BlazeFramework::Math::Vector2D startPosition)
	{
		RUNTIME_ASSERT(startPosition.x <= 1.0f && startPosition.x >= -1.0f, "ERROR: Entity's x start position is outside current window");
		RUNTIME_ASSERT(startPosition.y <= 1.0f && startPosition.y >= -1.0f, "ERROR: Entity's y start position is outside current window");

		this->position.x = startPosition.x;
		this->position.y = startPosition.y;

		for (int i = 0; i < numComponents; i++)
			components.at(i)->Initialize(this);

		return true;
	}

	bool Entity::Shutdown()
	{
		return true;
	}

	void Entity::Update()
	{
		for (int i = 0; i < numComponents; i++)
			components.at(i)->Update();
	}

	void Entity::AddComponent(Component* p_component)
	{
		RUNTIME_ASSERT(numComponents != numMaxComponents, "ERROR: Max amount of components reached!");

		components.push_back(p_component);
		numComponents++;
	}

}
