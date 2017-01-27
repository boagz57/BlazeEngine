#include "Precompiled.h"
#include "Graphics/Graphics.h"
#include "Graphics/Geometry.h"
#include "ShapeData.h"
#include "Universal/Globals.h"
#include "Ship.h"

Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::Update()
{
	position += (velocity * engineClock.TimeSinceLastFrame());

	graphics->Update(*this);
}

void Ship::Initialize()
{
	graphics->addGeometry(ShapeData::Triangle());
	graphics->CreateRenderable();
	graphics->InitializeBuffers();
}
