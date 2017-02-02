#include "Precompiled.h"
#include "Graphics/Graphics.h"
#include "Physics/Physics.h"
#include "Pawn.h"

namespace BlazeGameWorld
{
	Pawn::Pawn() :
		Entity(new BlazeGraphics::Graphics, new BlazePhysics::Physics)
	{}

	Pawn::~Pawn()
	{}

	bool Pawn::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		Entity::Initialize(startPosition, geometry);

		return false;
	}

	void Pawn::Update()
	{

	}
}