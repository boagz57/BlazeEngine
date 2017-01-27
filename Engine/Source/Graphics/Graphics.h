#pragma once
#include "GL/glew.h"
#include "Universal/UniversalTypeDefs.h"
#include "Math/Vector2D/Vector2D.h"
#include "Graphics/Renderable.h"
#include "Graphics/Geometry.h"
#include "DataStructures/Vector/Vector.h"
#include "GameWorld/Entity.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Initialize();
	void Draw();
	void InitializeBuffers();
	void Update(Entity& obj);
	Geometry* addGeometry(uint16 numVerts, Vector<BlazeFramework::Math::Vector2D> verticies, uint16 numIndicies, Vector<uint16> indices);
	Renderable* addRenderable(Geometry* mesh);

private:
	static const uint16 cMaxBufferSize = 1024;
	GLuint vertexBufferID;
	GLuint indexBufferID;

	Geometry mesh;
	Renderable renderable;

	Vector<BlazeFramework::Math::Vector2D> transformedVerts;
};

