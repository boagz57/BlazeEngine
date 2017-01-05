#pragma once
#include "../Universal/UniversalTypeDefs.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "Vector/Vector.h"

class Entity
{
public:
	Entity();
	~Entity();

	BlazeFramework::Vector<BlazeFramework::Math::Vertex3D> objVerts
	{
		BlazeFramework::Math::Vertex3D(+0.0f, +0.2f, 0.0f),
		BlazeFramework::Math::Vertex3D(-0.1f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(+0.1f, 0.0f, 0.0f)
	};

	void Initialize();
};

