#include "Precompiled.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "Physics/PhysicsComponents/CollisionComponent.h"
#include "Pawn.h"

namespace BlazeGameWorld
{
	Pawn::Pawn() 
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