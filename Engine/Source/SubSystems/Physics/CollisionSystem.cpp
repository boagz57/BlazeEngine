#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "Universal/Globals.h"
#include "Components/AABB.h"
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "CollisionSystem.h"

static Velocity* entityVelocity = nullptr;
static Position* entityPosition = nullptr;
static AABB* entityCollisionBox = nullptr;
static AABB* otherEntityCollisionBox = nullptr;
static uint16 numOfABBComponents = 0;

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

bool CollisionSystem::Initialize(SceneManager& scene)
{
	//Loop through all 'entities' in scene to see which entities match the
	//system bit mask (which entity 'keys' fit into the system 'lock').
	for (uint16 entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & COLLISION_MASK) == COLLISION_MASK)
		{
			entityPosition = &scene.positionComponents.at(entity);
			entityCollisionBox = &scene.AABBComponents.at(entity);

			//Set bounds of the collision box 
			entityCollisionBox->SetMax(+.1f, +.2f);
			entityCollisionBox->SetMin(-.1f, 0.0f);

			//Position collision box around entity's current position
			entityCollisionBox->SetMax(entityCollisionBox->GetMax().x + entityPosition->GetPosition().x, entityCollisionBox->GetMax().y + entityPosition->GetPosition().y);
			entityCollisionBox->SetMin(entityCollisionBox->GetMin().x + entityPosition->GetPosition().x, entityCollisionBox->GetMin().y + entityPosition->GetPosition().y);

			numOfABBComponents++;
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
	//First loop through all entity's and update their bounding box positions
	for (uint16 entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & COLLISION_MASK) == COLLISION_MASK)
		{
			entityVelocity = &scene.velocityComponents.at(entity);
			entityCollisionBox = &scene.AABBComponents.at(entity);

			entityCollisionBox->SetMax(entityCollisionBox->GetMax() + (entityVelocity->GetVelocity() * engineClock.TimeSinceLastFrame()));
			entityCollisionBox->SetMin(entityCollisionBox->GetMin() + (entityVelocity->GetVelocity() * engineClock.TimeSinceLastFrame()));

			//Need to reset velocity to zero to avoid 'floating' movement effect
			entityVelocity->SetVelocityX(0.0f);
			entityVelocity->SetVelocityY(0.0f);
		};
	};

	//Now check all entities against all other entities to see if any collisions are occurring
	for (uint16 entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & COLLISION_MASK) == COLLISION_MASK)
		{
			entityCollisionBox = &scene.AABBComponents.at(entity);

			for (int nextEntity = entity + 1; nextEntity < numOfABBComponents; nextEntity++)
			{
				otherEntityCollisionBox = &scene.AABBComponents.at(nextEntity);//TODO: Not sure if I need second for loop within this for loop. Just monitor things and see if the system has both objects detecting a collision and doing their corresponding actions
				CheckForCollision();
			};
		};
	};
}

//Free Standing Function Helper Classes
void CheckForCollision()
{
	//Exit returning NO intersection between bounding box
	if (entityCollisionBox->GetMax().x < otherEntityCollisionBox->GetMin().x || entityCollisionBox->GetMin().x > otherEntityCollisionBox->GetMax().x)
		return;
	//Exit returning NO intersection between bounding box
	if (entityCollisionBox->GetMax().y < otherEntityCollisionBox->GetMin().y || entityCollisionBox->GetMin().y > otherEntityCollisionBox->GetMax().y)
		return;

	//Exit returning YES there is intersection
	//between points and a collision has occurred
	LOG("Collision!!!!");
}
