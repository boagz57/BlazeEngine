#include "Precompiled.h"
#include "Graphics/ShapeData.h"
#include "Components/Component.h"
#include "GameWorld/SceneManager.h"
#include "RenderSystem.h"

static GLuint vertexBufferID;
static GLuint indexBufferID;

//The max buffer size in bytes I want to send down initially to GPU
static uint16 const c_MaxBufferSize = 1024;

//Used as a temporary storage container so we don't have to modify original
//geometry during transformations
Vector<BlazeFramework::Math::Vector2D> transformedVerts;
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

	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);

	glBufferData(GL_ARRAY_BUFFER, c_MaxBufferSize, nullptr, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, c_MaxBufferSize, nullptr, GL_DYNAMIC_DRAW);

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
			Position* entityPosition = &scene.positionComponents.at(entity);

			for (int i = 0; i < 3; i++)
			{
				transformedVerts.at(i) = BlazeGraphics::ShapeData::Triangle().vertices.at(i) + entityPosition->position;
			};

			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vector2D) * transformedVerts.size(), &transformedVerts.front());//TODO: Need to make it where I only send down geometry data once in initialize() func
			glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(uint16) * 3, &BlazeGraphics::ShapeData::Triangle().indicies.front());
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
		}
	}
}
