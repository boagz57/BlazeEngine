#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "Universal/UniversalTypeDefs.h"

class Geometry
{
	friend class Graphics;
	const uint16 numVerts;
	Vector<BlazeFramework::Math::Vertex3D> vertices;
	const uint16 numIndicies;
	Vector<uint16> indicies;
	uint renderMode;
};
