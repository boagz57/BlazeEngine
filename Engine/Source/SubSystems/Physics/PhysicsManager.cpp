#include "Precompiled.h"
#include "PhysicsManager.h"

namespace BlazePhysics
{
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

	void PhysicsManager::AddPhysicsComponent(BlazePhysics::CollisionComponent* physicsComponent)
	{
		physicsComponents.push_back(physicsComponent);
	}

	void PhysicsManager::Update()
	{
		for (int i = 0; i < physicsComponents.size(); i++)
		{
			for (int j = i + 1; j < physicsComponents.size(); j++)
			{
				physicsComponents.at(i)->CheckForCollision(physicsComponents.at(j)->GetCollisionBox());
			}
		}
	}
}