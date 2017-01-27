#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "Entity.h"

//TODO: Make sure to update all header files and make them lean and mean

class Ship : public Entity
{
public:
	Ship();
	~Ship();

	bool Initialize(sfloat velocity) override;
	bool Shutdown() override;

	void Update() override;
};

