#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"
#include "Components/Appearance.h"
#include "Components/Position.h"
#include "Components/Velocity.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	uint16 CreateEntity();
	uint16 CreateTriangle(BlazeFramework::Math::Vector2D position);

public:
	

private:
	friend class RenderSystem;

	//Acts as the 'keys' which will selectively fit into system 'locks'.
	Vector<uint32> bitMasks;

	//Component vectors. Each index of the vectors represents an entity.
	//So positionComponents.at(1) represents position with entity 1. 
	Vector<PositionComponent> positionComponents;
	Vector<Appearance> geometryComponents;
	Vector<VelocityComponent> velocityComponents;

	uint16 const numMaxEntities;
};

