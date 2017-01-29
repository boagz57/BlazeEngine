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

	bool Physics::Initialize()
	{
		return true;
	}

	bool Physics::Shutdown()
	{
		return true;
	}

	void Physics::Update(Entity& entity)
	{
		entity.position += (entity.velocity * engineClock.TimeSinceLastFrame());
	}
}
