#include "Precompiled.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "LowLevelInput/KeyboardHandling.h"
#include "Input/Keyboard/Keyboard.h"
#include "Universal/Globals.h"
#include "Graphics.h"


Graphics::Graphics()
{
	for (int i = 0; i < 3; i++)
	{
		transformedTriangle.at(i) = triangle.at(i);
	}
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

	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLushort) * 3, &indicies.front());
}

void Graphics::Update(Entity& obj)
{
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vertex3D) * triangle.size(), &triangle.front());
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

	if (BlazeInput::Keyboard::KeyPress(BlazeFramework::Key::RightArrow))
	{
		BlazeFramework::Math::Vertex3D velocity(.6f, 0.0f, 0.0f);
		for (int i = 0; i < 3; i++)
		{
			transformedTriangle.at(i) = transformedTriangle.at(i) + velocity * engineClock.TimeSinceLastFrame();
		};
	} 

	else if (BlazeInput::Keyboard::KeyPress(BlazeFramework::Key::LeftArrow))
	{
		BlazeFramework::Math::Vertex3D velocity(-.6f, 0.0f, 0.0f);
		for (int i = 0; i < 3; i++)
		{
			transformedTriangle.at(i) = transformedTriangle.at(i) + velocity * engineClock.TimeSinceLastFrame();
		};
	}

	glBufferSubData(GL_ARRAY_BUFFER, 0, transformedTriangle.size() * sizeof(BlazeFramework::Math::Vertex3D), &transformedTriangle.front());
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}
