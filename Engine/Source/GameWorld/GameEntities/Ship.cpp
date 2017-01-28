#include "Precompiled.h"
#include "Graphics/Renderer.h"
#include "Graphics/Geometry.h"
#include "Graphics/ShapeData.h"
#include "Universal/Globals.h"
#include "Ship.h"

Ship::Ship()
{
}

Ship::~Ship()
{
}

bool Ship::Initialize(sfloat velocity, BlazeFramework::Math::Vector2D startPosition)
{
	this->velocity.x = velocity;
	this->position.x = startPosition.x;
	this->position.y = startPosition.y;

	input->Initialize();

	graphics->addGeometry(BlazeGraphics::ShapeData::Triangle());
	graphics->CreateRenderable();
	graphics->InitializeBuffers();

	return true;
}

bool Ship::Shutdown()
{
	return false;
}

void Ship::Update()
{
	position += (velocity * engineClock.TimeSinceLastFrame());

	input->Update(*this);
	graphics->Update(*this);
}