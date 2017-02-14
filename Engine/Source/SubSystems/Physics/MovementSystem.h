#pragma once
#include "Components/Component.h"

#define MOVEMENT_MASK (PositionComponentMask | VelocityComponentMask)

class SceneManager;

class MovementSystem
{
public:
	MovementSystem();
	~MovementSystem();

	bool Initialize();
	bool Shutdown();

	void Update(SceneManager& scene);
};

