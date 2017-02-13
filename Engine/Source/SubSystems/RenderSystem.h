#pragma once
#include "GL/glew.h"
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"

class SceneManager;

class RenderSystem
{
public:

protected:

private:
	GLuint vertexBufferID;
	GLuint indexBufferID;
	uint16 const c_MaxBufferSize = 1024;

	uint16 const c_numTransformedVertices = 3;
	Vector<BlazeFramework::Math::Vector2D> transformedVerts;

	/////////////////////////////////////////////////////////////

public:
	RenderSystem();
	~RenderSystem();

	bool Initialize();
	bool Shutdown();

	void RenderScene(SceneManager& scene);

protected:

private:
};

