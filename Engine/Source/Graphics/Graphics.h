#pragma once
#include "GL/glew.h"
#include "Universal/UniversalTypeDefs.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "Graphics/Renderable.h"
#include "Graphics/Geometry.h"
#include "DataStructures/Vector/Vector.h"
#include "GameWorld/Entity.h"

class Graphics
{
public:
	Graphics();

	bool Initialize();
	void Draw();
	void InitializeBuffers();
	void Update(Entity& obj);
	Geometry* addGeometry(uint16 numVerts, Vector<BlazeFramework::Math::Vertex3D> verticies, uint16 numIndicies, Vector<uint16> indices);
	Renderable* addRenderable(Geometry* mesh);

private:
	static const uint16 cMaxBufferSize = 1024;
	GLuint vertexBufferID;
	GLuint indexBufferID;

	const uint16 numMaxGeometries = 10;
	uint16 numGeometries = 0;
	Vector<Geometry> geometries;

	const uint16 numMaxRenderables= 10;
	uint16 numRenderables = 0;
	Vector<Renderable> renderables;

	Vector<BlazeFramework::Math::Vertex3D> transformedTriangle
	{
		BlazeFramework::Math::Vertex3D(0.0f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(0.0f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(0.0f, 0.0f, 0.0f)
	};
};

