#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "Entity/Entity.h"

//TODO: Make sure to update all header files and make them lean and mean

namespace BlazeGameWorld
{
	class Enemy : public Entity
	{
	public:
		Enemy();
		~Enemy();

		bool Initialize(BlazeFramework::Math::Vector2D startPosition) override;
		bool Shutdown() override;

		void Update() override;
	};
}
