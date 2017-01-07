#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Framework/Math/Vertex3D/Vertex3D.h"
#include "DataStructures/Vector/Vector.h"

class Entity
{
public:
	Entity();
	~Entity();

	tVector<BlazeFramework::Math::Vertex3D> objVerts
	{
		BlazeFramework::Math::Vertex3D(+0.0f, +0.2f, 0.0f),
		BlazeFramework::Math::Vertex3D(-0.1f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(+0.1f, 0.0f, 0.0f)
	};

	void Initialize();
	virtual void Update() = 0;
};

