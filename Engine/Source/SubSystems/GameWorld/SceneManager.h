#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"
#include "Components/Appearance.h"
#include "Components/Position.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Update();

	uint16 CreateEntity();
	uint16 CreateTriangle(BlazeFramework::Math::Vector2D position);

public:
	

private:
	friend class RenderSystem;

	//Acts as the 'keys' which will selectively fit into system 'locks'.
	Vector<uint32> bitMasks;

	//Component vectors. Each index of the vectors represents an entity.
	//So positionComponents.at(0) represents position with entity 0. 
	Vector<PositionComponent> positionComponents;
	Vector<Appearance> geometryComponents;

	uint16 const numMaxEntities;
};

