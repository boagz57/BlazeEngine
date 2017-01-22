#include "Precompiled.h"
#include "Universal/Macro.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "LowLevelInput/KeyboardHandling.h"
#include "Input/Keyboard/Keyboard.h"
#include "Universal/Globals.h"
#include "Graphics.h"


Graphics::Graphics() : geometries(numMaxGeometries), renderables(numMaxRenderables)
{
}

bool Graphics::Initialize()
{
	return true;
}

void Graphics::Draw()
{
}

void Graphics::InitializeBuffers()
{
	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);

	glBufferData(GL_ARRAY_BUFFER, cMaxBufferSize, nullptr, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cMaxBufferSize, nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);
}

void Graphics::Update(Entity& obj)
{
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vertex3D) * renderables.at(0).mesh->vertices.size(), &renderables.at(0).mesh->vertices.front());
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(uint16) * renderables.at(0).mesh->indicies.size(), &renderables.at(0).mesh->indicies.front());
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}

Geometry* Graphics::addGeometry(uint16 numVerts, Vector<BlazeFramework::Math::Vertex3D> verticies, uint16 numIndicies, Vector<uint16> indices)
{
	RUNTIME_ASSERT(numGeometries != numMaxGeometries, "ERROR: number of geometries more than vector can hold!");
	
	Geometry& mesh = geometries.at(numGeometries);

	mesh.numVerts = numVerts;
	mesh.vertices = verticies;
	mesh.numIndicies = numIndicies;
	mesh.indicies = indices;

	return &mesh;
}

Renderable * Graphics::addRenderable(Geometry * mesh)
{
	RUNTIME_ASSERT(numRenderables != numMaxRenderables, "ERROR: number of renderables more than vector can hold!");

	Renderable& object = renderables.at(numRenderables++);
	object.mesh = mesh;

	return &object;
}
