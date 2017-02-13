#pragma once
#include "Components/Component.h"
#include "Math/Vector2D/Vector2D.h"
#include "GameWorld/SceneManager.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"

#define RENDER_MASK (PositionComponent)

void InitializeRenderSystem()
{
	GLuint vertexBufferID;
	GLuint indexBufferID;
	uint16 const c_MaxBufferSize = 1024;

	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);

	glBufferData(GL_ARRAY_BUFFER, c_MaxBufferSize, nullptr, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, c_MaxBufferSize, nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, nullptr);
}

void RenderSystem(SceneManager& scene)
{
	uint16 entity = 0;

	if ((scene.bitMasks.at(entity) & RENDER_MASK) == RENDER_MASK)
	{
		Position* position = &scene.positionComponents.at(entity);
		BlazeFramework::Math::Vector2D v{ 0.0f, 0.3f };
		Vector<uint16> indicies{ 0,1,2 };
		Vector<BlazeFramework::Math::Vector2D> transformedVerts
		{
			BlazeFramework::Math::Vector2D(0.0f, 0.2f),
			BlazeFramework::Math::Vector2D(-0.2f, 0.0f),
			BlazeFramework::Math::Vector2D(0.2f, 0.0f),
		};

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vector2D) * 3, &transformedVerts.front());
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(uint16) * 3, &indicies.front());
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	}
}