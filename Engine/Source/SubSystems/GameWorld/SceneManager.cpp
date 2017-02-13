#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Math/Vector2D/Vector2D.h"
#include "Components/Component.h"
#include "SceneManager.h"


SceneManager::SceneManager() :
	numMaxEntities(10)
{
	bitMasks.resize(numMaxEntities);
	positionComponents.resize(numMaxEntities);
	geometryComponents.resize(numMaxEntities);
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
}

uint16 SceneManager::CreateEntity()
{
	//There are no concrete entities. Only entity ID numbers. Each index 
	//in all container classes represents a separate entity.
	uint16 entity;
	for (entity = 0; entity < numMaxEntities; entity++)
	{
		//Return the first empty (no bits turned on in bitMask; no 
		//components attached) entity index found.
		if (bitMasks.at(entity) == NoComponent)
			return entity;
	}

	LOG("ERROR: Cannot create more entities!!");
	return numMaxEntities;
}

uint16 SceneManager::CreateTriangle(BlazeFramework::Math::Vector2D startPosition)
{
	uint16 entity = CreateEntity();

	bitMasks.at(entity) = PositionComponent;

	positionComponents.at(entity).position = startPosition;

	return entity;
}
