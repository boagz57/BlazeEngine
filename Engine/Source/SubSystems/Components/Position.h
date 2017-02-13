#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

struct Position
{
	Position();

	BlazeFramework::Math::Vector2D position;
};

Position::Position() :
	position(0.0f, 0.0f)
{}