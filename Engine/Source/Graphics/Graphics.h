#pragma once
#include "GL/glew.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "DataStructures/Vector/Vector.h"
#include "GameWorld/Entity.h"

class Graphics
{
public:
	Graphics();

	void Draw();
	void InitializeBuffers();
	void Update(Entity& obj);

private:
	static const uint16 cMaxBufferSize = 1024;
	GLuint vertexBufferID;
	GLuint indexBufferID;

	Vector<BlazeFramework::Math::Vertex3D> triangle
	{
		BlazeFramework::Math::Vertex3D(+0.0f, +0.2f, 0.0f),
		BlazeFramework::Math::Vertex3D(-0.1f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(+0.1f, 0.0f, 0.0f)
	};
	
	Vector<BlazeFramework::Math::Vertex3D> transformedTriangle
	{
		BlazeFramework::Math::Vertex3D(0.0f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(0.0f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(0.0f, 0.0f, 0.0f)
	};

	Vector<GLushort> indicies
	{
		0, 1, 2
	};
};

