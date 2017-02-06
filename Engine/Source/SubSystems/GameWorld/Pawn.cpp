#include "Precompiled.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"
#include "Physics/PhysicsManager.h"
#include "Graphics/GraphicsManager.h"
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
		components.push_back(BlazePhysics::PhysicsManager::CreatePhysicsComponent<BlazePhysics::CollisionComponent>());
		components.push_back(BlazeGraphics::GraphicsManager::CreateGraphicsComponent<BlazeGraphics::RendererComponent>());

		return false;
	}

	void Pawn::Update()
	{

	}
}