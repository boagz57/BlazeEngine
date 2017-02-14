#include "Precompiled.h"
#include "GameWorld/SceneManager.h"
#include "Components/AABBComponent.h"
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "CollisionSystem.h"

CollisionSystem::CollisionSystem()
{
}


CollisionSystem::~CollisionSystem()
{
}

bool CollisionSystem::Initialize()
{
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
			scene.AABBComponents.at(entity).max.x = +0.1f;
			scene.AABBComponents.at(entity).max.y = +0.2f;
			scene.AABBComponents.at(entity).min.x = -0.1f;
			scene.AABBComponents.at(entity).min.y = +0.0f;

			scene.AABBComponents.at(entity).max.y = +0.2f;
			scene.AABBComponents.at(entity).min.x = -0.1f;
		}
	}
}
