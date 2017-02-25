#pragma once
#include "Components/Component.h"

#define COLLISION_MASK (PositionComponent| AABBComponent)

class SceneManager;

namespace BPhysics
{
	class CollisionSystem
	{
	public:
		CollisionSystem();
		~CollisionSystem();

		bool Initialize(SceneManager& scene);
		bool Shutdown();

		void Update(SceneManager& scene);
	};
}