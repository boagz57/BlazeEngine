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

	bool Pawn::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry, BlazePhysics::PhysicsManager& physManager, BlazeGraphics::GraphicsManager& grphsManager)
	{
		Entity::Initialize(startPosition, geometry, physManager, grphsManager);
		components.push_back(physManager.CreatePhysicsComponent<BlazePhysics::CollisionComponent>());
		components.push_back(grphsManager.CreateGraphicsComponent<BlazeGraphics::RendererComponent>());

		for (int i = 0; i < 2; i++)
		{
			components.at(i)->Initialize(this);
		}

		return false;
	}

	void Pawn::Update()
	{
		for (int i = 0; i < 2; i++)
		{
			components.at(i)->Update();
		}
	}
}