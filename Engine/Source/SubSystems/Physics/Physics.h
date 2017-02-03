#pragma once

namespace BlazeGameWorld { class Entity; }

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
