#include "Precompiled.h"
#include "Graphics/ShapeData.h"
#include "Components/Component.h"
#include "GameWorld/SceneManager.h"
#include "RenderSystem.h"

static GLuint TriangleVertexBufferID;
static GLuint TriangleIndexBufferID;

//The max buffer size in bytes I want to send down initially to GPU
static uint16 const c_MaxBufferSize = 1024;

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
	using namespace BlazeGraphics;
	using namespace BlazeFramework;

	transformedVerts.resize(c_numTransformedVertices);

	glGenBuffers(1, &TriangleVertexBufferID);
	glGenBuffers(1, &TriangleIndexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, TriangleVertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, TriangleIndexBufferID);

	glBufferData(GL_ARRAY_BUFFER, (sizeof(Vector2D) * ShapeData::Triangle().vertices.size()), &ShapeData::Triangle().vertices.front(), GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(uint16) * ShapeData::Triangle().indicies.size()), &ShapeData::Triangle().indicies.front(), GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, nullptr);

	return false;
}

bool RenderSystem::Shutdown()
{
	return false;
}

void RenderSystem::Update(SceneManager& scene)
{
	uint16 entity = 0;

	//Loop through all 'entities' in scene to see which entities match the
	//render bit mask (which entity 'keys' fit into the render 'lock').
	for (entity = 0; entity < scene.numMaxEntities; entity++)
	{
		if ((scene.bitMasks.at(entity) & RENDER_MASK) == RENDER_MASK)
		{
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
		}
	}
}
