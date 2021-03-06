#pragma once
#include "Components/Component.h"

//TODO: Remove AppearanceComponentMask. Just using now to prevent second entity from moving
#define MOVEMENT_MASK (PositionComponent| VelocityComponent | AppearanceComponent)

class SceneManager;

namespace BPhysics
{
	class MovementSystem
	{
	public:
		MovementSystem();
		~MovementSystem();

		bool Initialize();
		bool Shutdown();

		void Update(SceneManager& scene);
	};
}