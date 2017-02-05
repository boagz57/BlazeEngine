#include "Precompiled.h"
#include "Macro.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "Physics/PhysicsComponents/CollisionComponent.h"
#include "Input/InputManager.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "Entity.h"

namespace BlazeGameWorld
{
	Entity::Entity() :
		position(0.0f, 0.0f),
		velocity(0.0f, 0.0f)
	{}

	Entity::~Entity()
	{}

	bool Entity::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		RUNTIME_ASSERT(startPosition.x <= 1.0f && startPosition.x >= -1.0f, "ERROR: Entity's x start position is outside current window");
		RUNTIME_ASSERT(startPosition.y <= 1.0f && startPosition.y >= -1.0f, "ERROR: Entity's y start position is outside current window");

		this->position.x = startPosition.x;
		this->position.y = startPosition.y;

		collision.Initialize(this);
		renderer.Initialize(this);

		renderer.addGeometry(geometry);
		renderer.CreateRenderable();
		renderer.InitializeBuffers();

		return true;
	}

	bool Entity::Shutdown()
	{
		collision.Shutdown();
		renderer.Shutdown();

		return true;
	}
}
