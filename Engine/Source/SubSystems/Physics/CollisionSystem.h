#pragma once
#include "Components/Component.h"

#define COLLISION_MASK (PositionComponent| AABBComponent)

class SceneManager;

class CollisionSystem
{
public:
	CollisionSystem();
	~CollisionSystem();

	bool Initialize(SceneManager& scene);
	bool Shutdown();

	void Update(SceneManager& scene);
};

//Free Standing Function Helper Classes
void CheckForCollision();
