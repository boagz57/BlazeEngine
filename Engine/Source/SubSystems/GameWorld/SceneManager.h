#pragma once
#include "DataStructures/Vector/Vector.h"
#include "GameWorld/Entity.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Update();

	BlazeGameWorld::Entity* CreateEntity();

private:
	uint16 numEntities;
	uint16 const numMaxEntities;

	//Used to store all Entity objects in the game and iterate over them to call their respective
	//Update() functions. One of the possible implementations of the Update pattern. 
	Vector<BlazeGameWorld::Entity> entities;
};

