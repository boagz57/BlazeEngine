#include "Precompiled.h"
#include "Graphics/Graphics.h"
#include "Input/Controller.h"
#include "Physics/Physics.h"
#include "Pawn.h"

namespace BlazeGameWorld
{
	Pawn::Pawn() 
	{}

	Pawn::Pawn(BlazeInput::Controller* controller) :
		Entity(new BlazeGraphics::Graphics, new BlazePhysics::Physics),
		controller(controller)
	{}

	Pawn::~Pawn()
	{}

	bool Pawn::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		Entity::Initialize(startPosition, geometry);
		controller->Initialize();

		return false;
	}

	void Pawn::Update()
	{

	}

}