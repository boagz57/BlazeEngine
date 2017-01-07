#pragma once
#include "GameWorld/Entity.h"

class Graphics
{
public:
	Graphics(Entity* obj);

	void Draw();
	void InitializeBuffers();

private:
	Entity* mObj;
};

