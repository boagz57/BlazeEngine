#include "Precompiled.h"
#include "Universal/Macro.h"
#include "SceneManager.h"
#include "GameWorld/Entity.h"


SceneManager::SceneManager() :
	numEntities(0),
	numMaxEntities(10)
{
	entities.reserve(numMaxEntities);
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	for (int i = 0; i < numEntities; i++)
		entities.at(i).Update();
}

BlazeGameWorld::Entity* SceneManager::CreateEntity()
{
	RUNTIME_ASSERT(numEntities != numMaxEntities, "ERROR: Maximum amount of entities reached!");

	BlazeGameWorld::Entity entity(numEntities);
	entities.push_back(entity);

	return &entities.at(numEntities++);
}
