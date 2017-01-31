#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "GameWorld/GameEntities/Pawn/Pawn.h"
#include "Graphics/Geometry.h"

//TODO: Make sure to update all header files and make them lean and mean

namespace BlazeGameWorld
{
	class NPC : public Pawn 
	{
	public:

	protected:

	private:

		////////////////////////////////////////////////////////////////////////

	public:
		NPC();
		~NPC();

		bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry) override;
		bool Shutdown() override;

		void Update() override;

	protected:

	private:
	};
}
