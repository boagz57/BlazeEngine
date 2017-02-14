#pragma once
#include "Components/Component.h"

#define COLLISION_MASK (PositionComponentMask | VelocityComponentMask | AABBComponentMask)

class SceneManager;

class CollisionSystem
{
public:
	CollisionSystem();
	~CollisionSystem();

	bool Initialize();
	bool Shutdown();

	void Update(SceneManager& scene);
};

