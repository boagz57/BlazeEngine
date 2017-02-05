#include "Precompiled.h"
#include "Macro.h"
#include "GameWorld/Entity.h"
#include "Universal/Globals.h"
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"

namespace BlazePhysics
{
	CollisionComponent::CollisionComponent() 
	{
	}

	CollisionComponent::~CollisionComponent()
	{
	}

	bool CollisionComponent::Initialize(BlazeGameWorld::Entity* p_entity)
	{
		this->p_entity = p_entity;

		collisionBox.max.x = 0.1f;
		collisionBox.max.y = 0.2f;
		collisionBox.min.x = -0.1f;
		collisionBox.min.y = 0.0f;

		collisionBox.max += p_entity->position;
		collisionBox.min += p_entity->position;

		return true;
	}

	bool CollisionComponent::Shutdown()
	{
		return true;
	}

	void CollisionComponent::Update()
	{
		collisionBox.max += (p_entity->velocity * engineClock.TimeSinceLastFrame());
		collisionBox.min += (p_entity->velocity * engineClock.TimeSinceLastFrame());
	}

	void CollisionComponent::CheckForCollision(BoundingBox otherCollisionBox)
	{
		//Exit returning NO intersection between bounding box
		if (this->collisionBox.max.x < otherCollisionBox.min.x || this->collisionBox.min.x > otherCollisionBox.max.x)
			return;
		//Exit returning NO intersection between bounding box
		if (this->collisionBox.max.y < otherCollisionBox.min.y || this->collisionBox.min.y > otherCollisionBox.max.y)
			return;

		//Exit returning YES there is intersection
		//between points and a collision has occurred
		LOG("Collision!!!!");
	}
}