#include "Precompiled.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include "Input/InputManager.h"
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"
#include "Universal/Globals.h"
#include "InputComponents/KeyboardComponent/KeyboardComponent.h"
#include "Player.h"

//TODO: move all game world classes out of GameEntities folder and delete it

namespace BlazeGameWorld
{
	Player::Player()
	{
	}

	Player::~Player()
	{
	}

	bool Player::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry, BlazePhysics::PhysicsManager& physManager, BlazeGraphics::GraphicsManager& grphsManager)
	{
		Pawn::Initialize(startPosition, geometry, physManager, grphsManager);
		keyboard.Initialize(this);
		
		return true;
	}

	bool Player::Shutdown()
	{
		Pawn::Shutdown();

		return true;
	}

	void Player::Update()
	{
		Pawn::Update();
		keyboard.Update();

	}
}