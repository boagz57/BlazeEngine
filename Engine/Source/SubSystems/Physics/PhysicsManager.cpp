#include "Precompiled.h"
#include "PhysicsManager.h"



namespace BlazePhysics
{
	uint16 PhysicsManager::numPhysicsComponents = 0;

	PhysicsManager::PhysicsManager()
	{
	}

	PhysicsManager::~PhysicsManager()
	{
	}

	bool PhysicsManager::Initialize()
	{
		physicsComponents.reserve(23);
		return false;
	}

	bool PhysicsManager::Shutdown()
	{
		return false;
	}

	void PhysicsManager::Update()
	{
		for (int i = 0; i < physicsComponents.size(); i++)
		{
			for (int j = i + 1; j < physicsComponents.size(); j++)
			{
				physicsComponents.at(i).CheckForCollision(physicsComponents.at(j).GetCollisionBox());
			}
		}
	}
}