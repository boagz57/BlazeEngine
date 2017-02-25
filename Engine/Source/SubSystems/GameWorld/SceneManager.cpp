#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Math/Vector3D.h"
#include "Components/Component.h"
#include "SceneManager.h"

SceneManager::SceneManager() :
	numMaxEntities(10)
{
}

SceneManager::~SceneManager()
{
}

bool SceneManager::Initialize()
{
	return true;
}

bool SceneManager::Shutdown()
{
	return true;
}

uint16 SceneManager::M_CreateEntity()
{
	uint16 entity;

	//There are no concrete entities. Only entity ID numbers. Each index 
	//in all container classes represents a separate entity.
	for (entity = 0; entity < numMaxEntities; entity++)
	{
		//Return the first empty (no bits turned on in bitMask; no 
		//components attached) entity index found.
		if (bitMasks.at(entity) == NoComponents)
			return entity;
	}

	RUNTIME_ASSERT(entity != numMaxEntities, "ERROR: Cannot create more entities. Reached maximum capacity!!");
	return numMaxEntities;
}

uint16 SceneManager::CreatePlayer(BlazeFramework::Vector3D startPosition, char8 * shapeToRender)
{
	RUNTIME_ASSERT(shapeToRender != nullptr, "ERROR: Need a valid shape to render!!!");//TODO: Need better assert system here to check that shape name matches a valid choice

	uint16 entity = M_CreateEntity();

	Position* entityPosition = &positionComponents.at(entity);
	Appearance* entityAppearance = &appearanceComponents.at(entity);

	//Set an entity to show as having certain components attached (creates
	//the 'key' for the entity to see if it will fit in a system's 'lock'.
	bitMasks.at(entity) = PositionComponent | AABBComponent | VelocityComponent | AppearanceComponent;

	entityPosition->SetPosition(startPosition);
	entityAppearance->SetRenderShape(shapeToRender);

	return entity;
}

uint16 SceneManager::CreateStaticEntity(BlazeFramework::Vector3D position, char8* shapeToRender)
{
	uint16 entity = M_CreateEntity();

	Position* entityPosition = &positionComponents.at(entity);
	Appearance* entityAppearance = &appearanceComponents.at(entity);

	//Set an entity to show as having certain components attached (creates
	//the 'key' for the entity to see if it will fit in a system's 'lock'.
	bitMasks.at(entity) = PositionComponent | AABBComponent | AppearanceComponent;

	entityPosition->SetPosition(position);
	entityAppearance->SetRenderShape(shapeToRender);

	return entity;
}
