#pragma once
#include "GameWorld/Entity.h"
#include "Graphics/Graphics.h"

class Triangle : public Entity
{
public:

	bool Initialize();
	void Update() override;

private:
	Graphics mGraphics;
};