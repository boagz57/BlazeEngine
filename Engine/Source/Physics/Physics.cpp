#include "Precompiled.h"
#include "Universal/Globals.h"
#include "Physics.h"

namespace BlazePhysics
{
	Physics::Physics()
	{
	}


	Physics::~Physics()
	{
	}

	void Physics::Update(Entity& entity)
	{
		entity.position += (entity.velocity * engineClock.TimeSinceLastFrame());
	}
}
