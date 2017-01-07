#pragma once
#include "GameWorld/Entity.h"

class Graphics
{
public:
	Graphics(Entity* pObject);

	void Draw();
	void InitializeBuffers();

private:
	Entity* mpObject;
};

