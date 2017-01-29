#pragma once
#include "Framework/LowLevelInput/KeyboardHandling.h"
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeInput
{
	class Input
	{
	public:
		Input();
		~Input();

		bool Initialize();
		bool Shutdown();

		void Update(BlazeGameWorld::Entity& entity);
	};
}


