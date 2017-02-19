#include "Precompiled.h"
#include "Graphics/ShapeData.h"
#include "Math/MatrixTransforms.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Components/Component.h"
#include "GameWorld/SceneManager.h"
#include "RenderSystem.h"

//Used as a temporary storage container so we don't have to modify original
//geometry during transformations
Vector<BlazeFramework::Vector2D> transformedVerts;
static uint16 const c_numTransformedVertices = 3;

RenderSystem::RenderSystem() 
{
}

RenderSystem::~RenderSystem()
{
}

bool RenderSystem::Initialize()
{
	transformedVerts.resize(c_numTransformedVertices);
	MyOpenGL::InitializeBuffers();

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
			BlazeFramework::Matrix4x4 translationMat = BlazeFramework::Translate(BlazeFramework::Vector3D(0.04f, 0.0f, 0.0f));
			MyOpenGL::sendUniformMat4Data("translationMatrix", &translationMat[0][0]);

			MyOpenGL::Draw();
		}
	}
}
