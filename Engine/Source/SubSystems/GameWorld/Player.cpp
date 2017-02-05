#include "Precompiled.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include "Input/InputManager.h"
#include "Physics/PhysicsComponents/CollisionComponent.h"
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
		collision.Update();

		position += (velocity * engineClock.TimeSinceLastFrame());

		renderer.Update();


		//Have to zero out velocity after updating every frame so that key input 
		//doesn't compound and cause the object to move in a direction its 
		//not meant to for a certain key press.
		this->velocity.x = 0;
		this->velocity.y = 0;
	}
}