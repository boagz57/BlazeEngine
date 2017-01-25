#pragma once
#include "Universal/UniversalTypeDefs.h"
#include <memory>
#include "Framework/Math/Vertex3D/Vertex3D.h"
#include "DataStructures/Vector/Vector.h"

class Graphics;

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Initialize() = 0;
	//Every object which inherits from this base class will have it's update function called from
	//world's GameLoop() function which iterates over a collection of objects each frame.
	virtual void Update() = 0;
	void AnotherFunc(); //TODO: Eventually have an actual default function for Entity to make it abstract

	BlazeFramework::Math::Vertex3D position;

protected:
	std::unique_ptr<Graphics> graphics;

	BlazeFramework::Math::Vertex3D oldPosition;
	BlazeFramework::Math::Vertex3D velocity;
};

