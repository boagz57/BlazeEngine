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

bool Ship::Initialize(sfloat velocity)
{
	this->velocity.x = velocity;

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

	graphics->Update(*this);
}