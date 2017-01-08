#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Framework/Math/Vertex3D/Vertex3D.h"
#include "DataStructures/Vector/Vector.h"

class Graphics;

class Entity
{
public:
	Entity();
	~Entity();

	void Initialize();
	virtual void Update();

	uint16 velocity;

private:
	Graphics* graphics;
};

