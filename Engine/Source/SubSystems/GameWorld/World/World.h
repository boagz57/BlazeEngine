#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "DataStructures/Vector/Vector.h"
#include <Array>
#include "GameWorld/GameEntities/Entity/Entity.h"

class World
{
public:
	World();
	~World();

	bool Initialize();
	bool Shutdown();

	void GameLoop();

private:
	//Used to store all Entity objects in the game and iterate over them to call their respective
	//Update() functions. One of the possible implementations of the Update pattern. 
	Vector<BlazeGameWorld::Entity*> entities;
	uint16 numEntities;
};

