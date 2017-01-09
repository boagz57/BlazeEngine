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
	//Used to store all Entity objects in the game and iterate over them to call their respective
	//Update() functions. One of the possible implementations of the Update pattern. 
	Vector<Entity*> mEntities;
	uint16 mNumberOfEntities;
};

