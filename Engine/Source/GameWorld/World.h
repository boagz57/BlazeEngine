#pragma once
#include "../Universal/UniversalTypeDefs.h"
#include "../Framework/Vector/Vector.h"
#include <Array>
#include "Entity.h"

class World
{
public:
	World();

	void GameLoop();

private:
	BlazeFramework::Vector<Entity*> m_entities;
	uint16 numberOfEntities;
};

