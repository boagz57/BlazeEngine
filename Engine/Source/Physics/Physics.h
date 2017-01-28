#pragma once
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazePhysics
{
	class Physics
	{
	public:
		Physics();
		~Physics();

		void Update(Entity& entity);
	};
}
