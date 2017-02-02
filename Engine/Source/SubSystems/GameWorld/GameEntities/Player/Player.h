#pragma once
#include <memory>
#include "Math/Vector2D/Vector2D.h"
#include "GameWorld/GameEntities/Pawn/Pawn.h"
#include "Input/Input.h"
#include "Graphics/Geometry.h"
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeInput { class Input; }

namespace BlazeGameWorld
{
	class Player : public Pawn 
	{
	public:

	protected:

	private:
		std::unique_ptr<BlazeInput::Input> input;

		//////////////////////////////////////////////////////////////////

	public:
		Player();
		~Player();

		bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry) override;
		bool Shutdown() override;

		void Update() override;

	protected:

	private:
	};
}
