#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "DataStructures/Vector/Vector.h"
#include <Array>
#include "GameWorld/Entity.h"

class World
{
public:

protected:

private:
	//////////////////////////////////////////////////////////////////

public:
	World();
	~World();

	bool Initialize();
	bool Shutdown();

	void GameLoop();

protected:

private:
};

