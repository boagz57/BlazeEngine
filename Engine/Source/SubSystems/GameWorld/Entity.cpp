#include "Precompiled.h"
#include "Macro.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include "SubSystems/Component.h"
#include "Input/InputManager.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "Entity.h"

namespace BlazeGameWorld
{
	Entity::Entity(uint16 ID) :
		EntityID(ID)
	{}

	bool Entity::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry, BlazePhysics::PhysicsManager& physmanager, BlazeGraphics::GraphicsManager& grphcsManager)
	{
		RUNTIME_ASSERT(startPosition.x <= 1.0f && startPosition.x >= -1.0f, "ERROR: Entity's x start position is outside current window");
		RUNTIME_ASSERT(startPosition.y <= 1.0f && startPosition.y >= -1.0f, "ERROR: Entity's y start position is outside current window");

		this->position.x = startPosition.x;
		this->position.y = startPosition.y;

		return true;
	}

	bool Entity::Shutdown()
	{
		return true;
	}
}
