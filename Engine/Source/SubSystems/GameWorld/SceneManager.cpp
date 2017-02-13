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
	appearanceComponents.resize(numMaxEntities);
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
