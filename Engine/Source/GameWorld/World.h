#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "DataStructures/Vector/Vector.h"
#include <Array>
#include "GameWorld/Entity.h"

class World
{
public:
	World();

	void GameLoop();

private:
	tVector<Entity*> m_entities;
	uint16 numberOfEntities;
};

