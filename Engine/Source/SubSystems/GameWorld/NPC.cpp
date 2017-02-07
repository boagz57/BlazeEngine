#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "GameWorld/Entity.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"
#include "NPC.h"

namespace BlazeGameWorld
{
	NPC::NPC() 
	{
	}

	NPC::~NPC()
	{
	}

	bool NPC::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry, BlazePhysics::PhysicsManager& physManager, BlazeGraphics::GraphicsManager& graphicsManager)
	{
		Pawn::Initialize(startPosition, geometry, physManager, graphicsManager);

		return true;
	}

	bool NPC::Shutdown()
	{
		Entity::Shutdown();

		return true;
	}

	void NPC::Update()
	{
		Pawn::Update();
	}
}
