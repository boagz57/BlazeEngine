#pragma once
#include "Math/Vertex2D/Vector2D.h"

class Geometry;

class Renderable
{
private:
	friend class Graphics;
	Geometry* mesh;

public:
	Renderable();
	BlazeFramework::Math::Vector2D location;
};

