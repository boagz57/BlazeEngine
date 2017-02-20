#include "Precompiled.h"
#include "Graphics/ShapeData.h"
#include "Math/MatrixTransforms.h"
#include "Graphics/ShapeData.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Components/Position.h"
#include "Components/Component.h"
#include "GameWorld/SceneManager.h"
#include "RenderSystem.h"

extern uint32 squareVertexBufferID;
extern uint32 squareIndexBufferID;
extern uint32 triangleVertexBufferID;
extern uint32 triangleIndexBufferID;

namespace BlazeGraphics
{
	RenderSystem::RenderSystem()
	{
	}

	RenderSystem::~RenderSystem()
	{
	}

	bool RenderSystem::Initialize(SceneManager& scene)
	{
		//Send all shape data down to GPU to be used for future rendering
		MyOpenGL::InitializeBuffers(ShapeData::Triangle().vertices.size(), &ShapeData::Triangle().vertices.front(), ShapeData::Triangle().indicies.size(), &ShapeData::Triangle().indicies.front(), &triangleVertexBufferID , &triangleIndexBufferID);
		MyOpenGL::InitializeBuffers(ShapeData::Square().vertices.size(), &ShapeData::Square().vertices.front(), ShapeData::Square().indicies.size(), &ShapeData::Square().indicies.front(), &squareVertexBufferID, &squareIndexBufferID);

		return false;
	}

	bool RenderSystem::Shutdown()
	{
		return false;
	}

	void RenderSystem::Update(SceneManager& scene)
	{
		//Loop through all 'entities' in scene to see which entities match the
		//render bit mask (which entity 'keys' fit into the render 'lock').
		for (uint16 entity = 0; entity < scene.numMaxEntities; entity++)
		{
			if ((scene.bitMasks.at(entity) & RENDER_MASK) == RENDER_MASK)
			{
				Position* entityPosition = &scene.positionComponents.at(entity);
				Appearance* entityApperance = &scene.appearanceComponents.at(entity);

				BlazeFramework::Matrix4x4 translationMatrix = BlazeFramework::Translate(BlazeFramework::Vector3D(entityPosition->position.x, entityPosition->position.y, 0.0f));
				MyOpenGL::sendUniformMat4Data("translationMatrix", &translationMatrix[0][0]);

				if (entityApperance->geometryShapeName == "Triangle")
					MyOpenGL::Draw(triangleVertexBufferID, triangleIndexBufferID, 3);

				else if (entityApperance->geometryShapeName == "Square")
					MyOpenGL::Draw(squareVertexBufferID, squareIndexBufferID, 6);
			}
		}
	}
}