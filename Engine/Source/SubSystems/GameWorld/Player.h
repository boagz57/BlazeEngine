#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "GameWorld/Pawn.h"
#include "Input/InputManager.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include "GameWorld/Entity.h"

namespace BlazeGameWorld
{
	class Player : public Pawn 
	{
	public:

	protected:

	private:
		BlazeInput::KeyboardComponent keyboard;

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
