#include "Precompiled.h"
#include "Graphics/Graphics.h"
#include "Graphics/Geometry.h"
#include "Input/Input.h"
#include "Physics/Physics.h"
#include "Graphics/ShapeData.h"
#include "Universal/Globals.h"
#include "Ship.h"

namespace BlazeGameWorld
{
	Ship::Ship()
	{
	}

	Ship::~Ship()
	{
	}

	bool Ship::Initialize(BlazeFramework::Math::Vector2D startPosition)
	{
		this->position.x = startPosition.x;
		this->position.y = startPosition.y;

		input->Initialize();
		physics->Initialize();
		renderer->Initialize();

		renderer->addGeometry(BlazeGraphics::ShapeData::Triangle());
		renderer->CreateRenderable();
		renderer->InitializeBuffers();

		return true;
	}

	bool Ship::Shutdown()
	{
		input->Shutdown();
		physics->Shutdown();
		renderer->Shutdown();

		return false;
	}

	void Ship::Update()
	{
		input->Update(*this);
		physics->Update(*this);
		renderer->Update(*this);

		//Have to zero out velocity after updating every frame so that key input doesn't compound and 
		//cause the object to move in a direction its not meant to for a certain key press.
		velocity.x = 0;
		velocity.y = 0;
	}
}