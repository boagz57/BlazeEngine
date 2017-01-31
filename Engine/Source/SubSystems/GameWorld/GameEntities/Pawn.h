#pragma once
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeInput { class Controller; }

namespace BlazeGameWorld
{
	class Pawn : public Entity
	{
	public:
		Pawn();
		~Pawn();

		virtual bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry) override;

		virtual void Update() override;

	protected:
		Pawn(BlazeInput::Controller* controller);

		std::unique_ptr<BlazeInput::Controller> controller;
	};
}
