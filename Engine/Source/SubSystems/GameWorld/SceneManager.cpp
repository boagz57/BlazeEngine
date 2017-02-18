#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Math/Vector2D.h"
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
	bitMasks.resize(numMaxEntities);
	positionComponents.resize(numMaxEntities);
	geometryComponents.resize(numMaxEntities);
	velocityComponents.resize(numMaxEntities);
	AABBComponents.resize(numMaxEntities);

	return false;
}

bool SceneManager::Shutdown()
{
	return false;
}

uint16 SceneManager::M_CreateEntity()
{
	//There are no concrete entities. Only entity ID numbers. Each index 
	//in all container classes represents a separate entity.
	for (uint16 entity = 0; entity < numMaxEntities; entity++)
	{
		//Return the first empty (no bits turned on in bitMask; no 
		//components attached) entity index found.
		if (bitMasks.at(entity) == NoComponents)
			return entity;
	}

	LOG("ERROR: Cannot create more entities!!");
	return numMaxEntities;
}

uint16 SceneManager::CreateTriangle(BlazeFramework::Math::Vector2D startPosition)
{
	uint16 entity = M_CreateEntity();

	//Set an entity to show as having certain components attached (creates
	//the 'key' for the entity to see if it will fit in a system's 'lock'.
	bitMasks.at(entity) = PositionComponent | AABBComponent | VelocityComponent | AppearanceComponent;//TODO: Remove Appearance mask

	positionComponents.at(entity).position = startPosition;

	return entity;
}

uint16 SceneManager::CreateStaticEntity(BlazeFramework::Math::Vector2D startPosition)
{
	uint16 entity = M_CreateEntity();

	//Set an entity to show as having certain components attached (creates
	//the 'key' for the entity to see if it will fit in a system's 'lock'.
	bitMasks.at(entity) = PositionComponent | AABBComponent;

	positionComponents.at(entity).position = startPosition;

	return entity;
}
