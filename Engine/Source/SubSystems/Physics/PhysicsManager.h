#pragma once
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"
#include "DataStructures/Vector/Vector.h"

namespace BlazePhysics
{
	class PhysicsManager
	{
	public:
		PhysicsManager();
		~PhysicsManager();

		bool Initialize();
		bool Shutdown();

		void AddPhysicsComponent(BlazePhysics::CollisionComponent* physicsComponent);

		void Update();

	private:
		Vector<BlazePhysics::CollisionComponent*> physicsComponents;
	};
}