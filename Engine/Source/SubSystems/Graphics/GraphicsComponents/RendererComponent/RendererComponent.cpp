#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GLM/gtx/matrix_transform_2d.hpp"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "GameWorld/Entity.h"
#include "LowLevelInput/KeyboardHandling.h"
#include "Input/InputManager.h"
#include "Universal/Globals.h"
#include "RendererComponent.h"

//TODO: Need to abstract away opengl functions from this class

namespace BlazeGraphics
{
	RendererComponent::RendererComponent()
	{}

	RendererComponent::~RendererComponent()
	{}

	bool RendererComponent::Initialize(BlazeGameWorld::Entity* p_entity)
	{
		transformedVerts.resize(c_numTransformedVertices);
		this->p_entity = p_entity;

		return true;
	}

	bool RendererComponent::Shutdown()
	{
		glDeleteBuffers(1, &vertexBufferID);
		glDeleteBuffers(1, &indexBufferID);

		return false;
	}

	void RendererComponent::InitializeBuffers()
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

	void RendererComponent::Update()
	{
		renderable.location = p_entity->position;

		for (int i = 0; i < 3; i++)
		{
			transformedVerts.at(i) = renderable.mesh.vertices.at(i) + renderable.location;
		};

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vector2D) * transformedVerts.size(), &transformedVerts.front());
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(uint16) * renderable.mesh.indicies.size(), &renderable.mesh.indicies.front());
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	}

	void RendererComponent::addGeometry(Geometry geometry)
	{
		mesh.numVerts = geometry.numVerts;
		mesh.vertices = geometry.vertices;
		mesh.numIndicies = geometry.numIndicies;
		mesh.indicies = geometry.indicies;
	}

	void RendererComponent::CreateRenderable()
	{
		renderable.mesh = mesh;
	}
}