#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "Universal/Globals.h"
#include "Components/AABBComponent.h"
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "CollisionSystem.h"

static PositionComponent* entityPosition = nullptr;
static AABBComponent* entityCollisionBox = nullptr;
static AABBComponent* otherEntityCollisionBox = nullptr;
static PositionComponent* otherEntityPos = nullptr;

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

bool CollisionSystem::Initialize(SceneManager& scene)
{
	uint16 entity = 0;

	//Loop through all 'entities' in scene to see which entities match the
	//system bit mask (which entity 'keys' fit into the system 'lock').
	for (entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & COLLISION_MASK) == COLLISION_MASK)
		{
			entityPosition = &scene.positionComponents.at(entity);
			entityCollisionBox = &scene.AABBComponents.at(entity);

			//Set bounds of the collision box 
			entityCollisionBox->max.x = +0.1f;
			entityCollisionBox->max.y = +0.2f;
			entityCollisionBox->min.x = -0.1f;
			entityCollisionBox->min.y = +0.0f;

			//Position collision box around entity's current position
			entityCollisionBox->max += entityPosition->position;
			entityCollisionBox->min += entityPosition->position;
		}
	}

	return false;
}

bool CollisionSystem::Shutdown()
{
	return false;
}

void CollisionSystem::Update(SceneManager& scene)
{
	uint16 entity = 0;

	//Loop through all 'entities' in scene to see which entities match the
	//system bit mask (which entity 'keys' fit into the system 'lock').
	for (entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & COLLISION_MASK) == COLLISION_MASK)
		{
			VelocityComponent* entityVelocity = &scene.velocityComponents.at(entity);
			entityCollisionBox = &scene.AABBComponents.at(entity);

			entityCollisionBox->max += (entityVelocity->velocity * engineClock.TimeSinceLastFrame());
			entityCollisionBox->min += (entityVelocity->velocity * engineClock.TimeSinceLastFrame());

			//Need to reset velocity to zero to avoid 'floating' movement
			entityVelocity->velocity.x = 0;
			entityVelocity->velocity.y = 0;

			if (entity != 0)
			{
				otherEntityCollisionBox = &scene.AABBComponents.at(entity - 1);
				otherEntityPos = &scene.positionComponents.at(entity -1);
				CheckForCollision();
			}
		};
	};
}

//Free Standing Function Helper Classes
void CheckForCollision()
{
	//Exit returning NO intersection between bounding box
	if (entityCollisionBox->max.x < otherEntityCollisionBox->min.x || entityCollisionBox->min.x > otherEntityCollisionBox->max.x)
		return;
	//Exit returning NO intersection between bounding box
	if (entityCollisionBox->max.y < otherEntityCollisionBox->min.y || entityCollisionBox->min.y > otherEntityCollisionBox->max.y)
		return;

	//Exit returning YES there is intersection
	//between points and a collision has occurred
	LOG("Collision!!!!");
}
