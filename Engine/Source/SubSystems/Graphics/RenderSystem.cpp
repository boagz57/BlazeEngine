#include "Sprite.h"
#include "Universal/Macro.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "RenderSystem.h"

extern uint32 squareVertexBufferID;
extern uint32 squareIndexBufferID;
extern uint32 triangleVertexBufferID;
extern uint32 triangleIndexBufferID;

namespace RenderSystem
{
	void Initialize()
	{
	}

	uint16 LoadSprite(BGraphics::Sprite sprite)
	{
		MyOpenGL::InitializeBuffers(sprite.vertices.size(), &sprite.vertices.front(), sprite.indicies.size(), &sprite.indicies.front(), &triangleVertexBufferID, &triangleIndexBufferID);

		static uint16 numSprites = 0;
		++numSprites;

		return numSprites;
	}

	void AttachSprite()
	{

	}

	void RenderCharacter(Character* character)
	{
	}
}
