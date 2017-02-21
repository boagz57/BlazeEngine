#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector3D.h"
#include "Components/Appearance.h"
#include "Components/Position.h"
#include "Components/Velocity.h"
#include "Components/AABB.h"

namespace BlazeGraphics { class RenderSystem; }

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	bool Initialize();
	bool Shutdown();

	uint16 CreatePlayer(BlazeFramework::Vector3D position, char8* shapeToRender);
	uint16 CreateStaticEntity(BlazeFramework::Vector3D position, char8* shapeToRender);

protected:

private:
	uint16 M_CreateEntity();

	///////////////////////////////////////////////////////////

public:
	

private:
	//So only systems have access to component arrays
	friend class BlazeGraphics::RenderSystem;
	friend class InputSystem;
	friend class MovementSystem;
	friend class CollisionSystem;

	//Acts as the 'keys' which will selectively fit into system 'locks'.
	Vector<uint32> bitMasks;

	//Component arrays. Each index of the arrays represents an entity.
	//So positionComponents.at(1) represents entity 1's position. 
	Vector<Position> positionComponents;
	Vector<Appearance> appearanceComponents;
	Vector<Velocity> velocityComponents;
	Vector<AABB> AABBComponents;

	uint16 const numMaxEntities;
};
