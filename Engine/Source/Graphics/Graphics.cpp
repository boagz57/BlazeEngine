#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GLM/gtx/matrix_transform_2d.hpp"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "LowLevelInput/KeyboardHandling.h"
#include "Input/Keyboard/Keyboard.h"
#include "Universal/Globals.h"
#include "Graphics.h"


Graphics::Graphics() 
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
	object.location += obj.position;
	for (int i = 0; i < 3; i++)
	{
		object.mesh->vertices.at(0) += object.location;
	};

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vertex3D) * object.mesh->vertices.size(), &object.mesh->vertices.front());
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(uint16) * object.mesh->indicies.size(), &object.mesh->indicies.front());
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}

Geometry* Graphics::addGeometry(uint16 numVerts, Vector<BlazeFramework::Math::Vertex3D> verticies, uint16 numIndicies, Vector<uint16> indices)
{
	mesh.numVerts = numVerts;
	mesh.vertices = verticies;
	mesh.numIndicies = numIndicies;
	mesh.indicies = indices;

	return &mesh;
}

Renderable * Graphics::addRenderable(Geometry * mesh)
{
	object.mesh = mesh;

	return &object;
}
