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

	bool Player::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		Pawn::Initialize(startPosition, geometry);
		keyboard.Initialize(this);
		
		return true;
	}

	bool Player::Shutdown()
	{
		Entity::Shutdown();

		return true;
	}

	void Player::Update()
	{
		keyboard.Update();


	}
}