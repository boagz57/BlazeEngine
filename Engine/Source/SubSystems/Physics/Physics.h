#pragma once
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazePhysics
{
	class Physics
	{
	public:
		Physics();
		~Physics();

		bool Initialize();
		bool Shutdown();

		void Update(BlazeGameWorld::Entity& entity);
	};
}
