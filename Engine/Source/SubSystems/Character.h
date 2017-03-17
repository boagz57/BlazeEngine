#pragma once
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "Components/Appearance.h"

struct Character
{
	Position position;
	Velocity velocity;
	Appearance sprite;
};
