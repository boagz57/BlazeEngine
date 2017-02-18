#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

struct AABB
{
	//Bottom left corner of box
	BlazeFramework::Math::Vector2D min;
	//Top right corner of box
	BlazeFramework::Math::Vector2D max;
};