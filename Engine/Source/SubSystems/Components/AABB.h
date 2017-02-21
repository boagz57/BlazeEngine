#pragma once
#include "Math/Vector3D.h"
#include "Universal/UniversalTypeDefs.h"

//This component provides means for a simple collision box around entity
struct AABB
{
	BlazeFramework::Vector3D GetMin() const { return min; }
	BlazeFramework::Vector3D GetMax() const { return max; }

	void SetMin(sfloat minX, sfloat minY) { min.x = minX; min.y = minY; }
	void SetMin(BlazeFramework::Vector3D newMin) { min = newMin; }

	void SetMax(sfloat maxX, sfloat maxY) { max.x = maxX; max.y = maxY; }
	void SetMax(BlazeFramework::Vector3D newMax) { max = newMax; }

private:
	//Bottom left corner of box
	BlazeFramework::Vector3D min;
	//Top right corner of box
	BlazeFramework::Vector3D max;
};