#pragma once
#include "GL/glew.h"
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"

//Adding what components the system requires in order to process information
#define RENDER_MASK (PositionComponentMask)

class SceneManager;

class RenderSystem
{
public:

protected:

private:
	GLuint vertexBufferID;
	GLuint indexBufferID;
	uint16 const c_MaxBufferSize;

	uint16 const c_numTransformedVertices;
	Vector<BlazeFramework::Math::Vector2D> transformedVerts;

	/////////////////////////////////////////////////////////////

public:
	RenderSystem();
	~RenderSystem();

	bool Initialize();
	bool Shutdown();

	void Update(SceneManager& scene);

protected:

private:
};