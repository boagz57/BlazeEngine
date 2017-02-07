#include "Precompiled.h"
#include "PhysicsManager.h"



namespace BlazePhysics
{
	uint16 PhysicsManager::numPhysicsComponents = 0;
	
	PhysicsManager::PhysicsManager()
	{
		physicsComponents.reserve(23);
	}

	PhysicsManager::~PhysicsManager()
	{
	}

	bool PhysicsManager::Initialize()
	{
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