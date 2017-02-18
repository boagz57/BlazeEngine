#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"
#include "Components/Appearance.h"
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "Components/AABB.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	bool Initialize();
	bool Shutdown();

	uint16 CreateTriangle(BlazeFramework::Math::Vector2D position);
	uint16 CreateStaticEntity(BlazeFramework::Math::Vector2D position);

protected:

private:
	uint16 M_CreateEntity();

	///////////////////////////////////////////////////////////

public:
	

private:
	friend class RenderSystem;
	friend class InputSystem;
	friend class MovementSystem;
	friend class CollisionSystem;

	//Acts as the 'keys' which will selectively fit into system 'locks'.
	Vector<uint32> bitMasks;

	//Component vectors. Each index of the vectors represents an entity.
	//So positionComponents.at(1) represents position with entity 1. 
	Vector<Position> positionComponents;
	Vector<Appearance> geometryComponents;
	Vector<Velocity> velocityComponents;
	Vector<AABB> AABBComponents;

	uint16 const numMaxEntities;
};
