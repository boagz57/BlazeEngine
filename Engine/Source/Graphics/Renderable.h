#pragma once
#include "Math/Vector2D/Vector2D.h"

class Geometry;

class Renderable
{
public:
	Renderable();
	~Renderable();

	BlazeFramework::Math::Vector2D location;

private:
	friend class Graphics;
	Geometry* mesh;
};

