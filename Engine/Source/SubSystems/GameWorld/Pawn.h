#pragma once
#include "GameWorld/Entity.h"

namespace BlazeGameWorld
{
	class Pawn : public Entity
	{
	public:

	protected:

	private:

		///////////////////////////////////////////////////////////////////////

	public:
		Pawn();
		~Pawn();

		virtual bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry, BlazePhysics::PhysicsManager& physManager, BlazeGraphics::GraphicsManager& grphsManager) override;

		virtual void Update() override;

	protected:

	private:
	};
}
