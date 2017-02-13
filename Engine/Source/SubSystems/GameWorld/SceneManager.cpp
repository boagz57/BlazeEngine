#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Math/Vector2D/Vector2D.h"
#include "Components/Component.h"
#include "SceneManager.h"
#include "GameWorld/Entity.h"


SceneManager::SceneManager() :
	numMaxEntities(10)
{
	bitMasks.reserve(numMaxEntities);
	positionComponents.reserve(numMaxEntities);
	appearanceComponents.reserve(numMaxEntities);
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
}

uint16 SceneManager::CreateEntity()
{
	uint16 entity;
	for (entity = 0; entity < numMaxEntities; entity++)
	{
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
