#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"
#include "Components/Appearance.h"
#include "Components/Position.h"
#include "GameWorld/Entity.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Update();

	uint16 CreateEntity();
	uint16 CreateTriangle(BlazeFramework::Math::Vector2D position);

private:
	uint16 const numMaxEntities;
	Vector<uint16> bitMasks;

	Vector<Position> positionComponents;
	Vector<Appearance> appearanceComponents;
};

