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

		void Update();

		template <typename PhysicsComponentType>
		static PhysicsComponentType* CreatePhysicsComponent();

	private:
		static uint16 numPhysicsComponents;
		Vector<BlazePhysics::CollisionComponent> physicsComponents;
	};


	//template definitions
	template <typename PhysicsComponentType>
	PhysicsComponentType* PhysicsManager::CreatePhysicsComponent()
	{
		PhysicsComponentType physicsComponent;
		physicsComponents.push_back(physicsComponent);

		return &physicsComponent.at(numPhysicsComponents++);
	}
}