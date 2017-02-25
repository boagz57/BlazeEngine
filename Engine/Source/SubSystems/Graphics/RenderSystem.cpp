#include "Precompiled.h"
#include "Universal/Macro.h"
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

static Position* entityPosition = nullptr;
static Appearance* entityAppearance = nullptr;

namespace BGraphics
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

		return true;
	}

	bool RenderSystem::Shutdown()
	{
		return true;
	}

	void RenderSystem::Update(SceneManager& scene)
	{
		//Loop through all 'entities' in scene to see which entities match the
		//render bit mask (which entity 'keys' fit into the render 'lock').
		for (uint16 entity = 0; entity < scene.numMaxEntities; entity++)
		{
			if ((scene.bitMasks.at(entity) & RENDER_MASK) == RENDER_MASK)
			{
				entityPosition = &scene.positionComponents.at(entity);
				entityAppearance = &scene.appearanceComponents.at(entity);

				//Use current entity position to store how much to translate vertices on GPU
				BlazeFramework::Matrix4x4 translationMatrix = BlazeFramework::Translate(BlazeFramework::Vector3D(entityPosition->GetPosition().x, entityPosition->GetPosition().y, 0.0f));
				//TODO:Add ortho projection and rotation matrices to the caclulations

				BlazeFramework::Matrix4x4 fullTransformMatrix = translationMatrix;

				MyOpenGL::sendUniformMat4Data("fullTransformMatrix", &fullTransformMatrix[0][0]);

				if (entityAppearance->GetShapeName() == "Triangle")
					MyOpenGL::Draw(triangleVertexBufferID, triangleIndexBufferID, 3);

				else if (entityAppearance->GetShapeName() == "Square")
					MyOpenGL::Draw(squareVertexBufferID, squareIndexBufferID, 6);
			}
		}
	}
}