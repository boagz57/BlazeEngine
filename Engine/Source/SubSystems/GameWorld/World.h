#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Universal/DataStructures/Vector.h"
#include <Array>

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

