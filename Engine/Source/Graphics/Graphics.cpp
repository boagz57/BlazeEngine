#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GLM/gtx/matrix_transform_2d.hpp"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "LowLevelInput/KeyboardHandling.h"
#include "Input/Input.h"
#include "Universal/Globals.h"
#include "Graphics.h"

namespace BlazeGraphics
{
	Graphics::Graphics() : transformedVerts(3)//TODO: Move to initialize() function
	{}

	Graphics::~Graphics()
	{}

	bool Graphics::Initialize()
	{
		return true;
	}

	bool Graphics::Shutdown()
	{
		glDeleteBuffers(1, &vertexBufferID);
		glDeleteBuffers(1, &indexBufferID);

		return true;
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
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, nullptr);
	}

	void Graphics::Update(Entity& entity)
	{
		renderable.location = entity.GetPosition();

		for (int i = 0; i < 3; i++)
		{
			transformedVerts.at(i) = renderable.mesh.vertices.at(i) + renderable.location;
		};

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vector2D) * transformedVerts.size(), &transformedVerts.front());
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(uint16) * renderable.mesh.indicies.size(), &renderable.mesh.indicies.front());
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	}

	void Graphics::addGeometry(Geometry geometry)
	{
		mesh.numVerts = geometry.numVerts;
		mesh.vertices = geometry.vertices;
		mesh.numIndicies = geometry.numIndicies;
		mesh.indicies = geometry.indicies;
	}

	void Graphics::CreateRenderable()
	{
		renderable.mesh = mesh;
	}
}