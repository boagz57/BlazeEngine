#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "Universal/UniversalTypeDefs.h"

class Geometry
{
private:
	//TODO: Make empty constructors for all classes (not just this one)
	friend class Graphics;
	uint16 numVerts;
	Vector<BlazeFramework::Math::Vertex3D> vertices;
	uint16 numIndicies;
	Vector<uint16> indicies;
	uint renderMode;
};
