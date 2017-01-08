#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Framework/Math/Vertex3D/Vertex3D.h"
#include "DataStructures/Vector/Vector.h"

class Entity
{
public:
	Entity();
	~Entity();

	void Initialize();
	virtual void Update() = 0;
};

