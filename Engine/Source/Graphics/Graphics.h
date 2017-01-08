#pragma once
#include "Math/Vertex3D/Vertex3D.h"
#include "GameWorld/Entity.h"

class Graphics
{
public:
	Graphics();

	void Draw();
	void InitializeBuffers();

private:
	Vector<BlazeFramework::Math::Vertex3D> triangle
	{
		BlazeFramework::Math::Vertex3D(+0.0f, +0.2f, 0.0f),
		BlazeFramework::Math::Vertex3D(-0.1f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(+0.1f, 0.0f, 0.0f)
	};
};

