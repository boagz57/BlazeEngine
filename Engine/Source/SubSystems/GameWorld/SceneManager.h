#pragma once
#include "Universal/DataStructures/Array.h"
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
	Array<uint32, 10> bitMasks;

	//Component arrays. Each index of the arrays represents an entity.
	//So positionComponents.at(1) represents entity 1's position. 
	Array<Position, 10> positionComponents;
	Array<Appearance, 10> appearanceComponents;
	Array<Velocity, 10> velocityComponents;
	Array<AABB, 10> AABBComponents;

	uint16 const numMaxEntities = 10;
};
