#pragma once
#include "Math/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

//This component provides means for a simple collision box around entity
struct AABB
{
	BlazeFramework::Vector2D GetMin() const { return min; }
	BlazeFramework::Vector2D GetMax() const { return max; }

	void SetMin(sfloat minX, sfloat minY) { min.x = minX; min.y = minY; }
	void SetMin(BlazeFramework::Vector2D newMin) { min = newMin; }

	void SetMax(sfloat maxX, sfloat maxY) { max.x = maxX; max.y = maxY; }
	void SetMax(BlazeFramework::Vector2D newMax) { max = newMax; }

private:
	//Bottom left corner of box
	BlazeFramework::Vector2D min;
	//Top right corner of box
	BlazeFramework::Vector2D max;
};