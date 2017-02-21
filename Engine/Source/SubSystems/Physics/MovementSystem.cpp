#include "Precompiled.h"
#include "Universal/Globals.h"
#include "Components/Velocity.h"
#include "GameWorld/SceneManager.h"
#include "Components/Position.h"
#include "MovementSystem.h"

static Position* entityPosition = nullptr;
static Velocity* entityVelocity = nullptr;

MovementSystem::MovementSystem()
{
}

MovementSystem::~MovementSystem()
{
}

bool MovementSystem::Initialize()
{
	return false;
}

bool MovementSystem::Shutdown()
{
	return false;
}

void MovementSystem::Update(SceneManager& scene)
{
	uint16 entity = 0;

	//Loop through all 'entities' in scene to see which entities match the
	//system bit mask (which entity 'keys' fit into the system 'lock').
	for (entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & MOVEMENT_MASK) == MOVEMENT_MASK)
		{
			entityPosition = &scene.positionComponents.at(entity);
			entityVelocity = &scene.velocityComponents.at(entity);
			
			//Set new entity position that's based on the entity's velocity
			entityPosition->SetPosition(entityPosition->GetPosition() += entityVelocity->GetVelocity() * engineClock.TimeSinceLastFrame());
		}
	}
}
