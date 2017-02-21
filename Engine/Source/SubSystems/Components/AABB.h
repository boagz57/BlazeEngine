#pragma once
#include "Math/Vector3D.h"
#include "Universal/UniversalTypeDefs.h"

//This component provides means for a simple collision box around entity
struct AABB
{
	inline BlazeFramework::Vector3D GetMin() const { return min; }
	inline BlazeFramework::Vector3D GetMax() const { return max; }

	inline void SetMin(sfloat minX, sfloat minY) { min.x = minX; min.y = minY; }
	inline void SetMin(BlazeFramework::Vector3D newMin) { min = newMin; }

	inline void SetMax(sfloat maxX, sfloat maxY) { max.x = maxX; max.y = maxY; }
	inline void SetMax(BlazeFramework::Vector3D newMax) { max = newMax; }

private:
	//Bottom left corner of box
	BlazeFramework::Vector3D min;
	//Top right corner of box
	BlazeFramework::Vector3D max;
};