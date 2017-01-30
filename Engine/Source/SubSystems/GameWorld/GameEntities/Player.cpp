#include "Precompiled.h"
#include "Graphics/Graphics.h"
#include "Graphics/Geometry.h"
#include "Input/Input.h"
#include "Input/PlayerController.h"
#include "Physics/Physics.h"
#include "Graphics/ShapeData.h"
#include "Universal/Globals.h"
#include "Player.h"

namespace BlazeGameWorld
{
	Player::Player() :
		Entity(new BlazeGraphics::Graphics, new BlazePhysics::Physics, new BlazeInput::PlayerController)
	{
	}

	Player::~Player()
	{
	}

	bool Player::Initialize(BlazeFramework::Math::Vector2D startPosition)
	{
		RUNTIME_ASSERT(startPosition.x <= 1.0f && startPosition.x >= -1.0f, "ERROR: Entity's x start position is outside current window");
		RUNTIME_ASSERT(startPosition.y <= 1.0f && startPosition.y >= -1.0f, "ERROR: Entity's y start position is outside current window");

		this->position.x = startPosition.x;
		this->position.y = startPosition.y;

		controller->Initialize();
		physics->Initialize();
		renderer->Initialize();

		renderer->addGeometry(BlazeGraphics::ShapeData::Triangle());
		renderer->CreateRenderable();
		renderer->InitializeBuffers();

		return true;
	}

	bool Player::Shutdown()
	{
		controller->Shutdown();
		physics->Shutdown();
		renderer->Shutdown();

		delete physics;
		delete renderer;
		delete controller;

		return true;
	}

	void Player::Update()
	{
		controller->Update(*this);
		physics->Update(*this);
		renderer->Update(*this);

		//Have to zero out velocity after updating every frame so that key input doesn't compound and 
		//cause the object to move in a direction its not meant to for a certain key press.
		this->velocity.x = 0;
		this->velocity.y = 0;
	}
}