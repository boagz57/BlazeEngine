#pragma once
#include "Math/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

//This component provides means for a simple collision box around entity
struct AABB
{
	//Bottom left corner of box
	BlazeFramework::Vector2D min;
	//Top right corner of box
	BlazeFramework::Vector2D max;
};