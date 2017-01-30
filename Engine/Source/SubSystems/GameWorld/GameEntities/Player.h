#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "Graphics/Geometry.h"
#include "Entity/Entity.h"

//TODO: Make sure to update all header files and make them lean and mean

namespace BlazeGameWorld
{
	class Player : public Entity
	{
	public:
		Player();
		~Player();

		bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry) override;
		bool Shutdown() override;

		void Update() override;
	};
}
