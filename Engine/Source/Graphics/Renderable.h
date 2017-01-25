#pragma once
#include "Math/Vertex3D/Vertex3D.h"

class Geometry;

class Renderable
{
private:
	friend class Graphics;
	Geometry* mesh;

public:
	Renderable();
	BlazeFramework::Math::Vertex3D location;
};

