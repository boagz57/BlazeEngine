#pragma once
#include "Universal/UniversalTypeDefs.h"
#include <memory>
#include "Math/Vector2D/Vector2D.h"
#include "DataStructures/Vector/Vector.h"

class Graphics;

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool Initialize(sfloat velocity) = 0;
	virtual bool Shutdown() = 0;

	//Every object which inherits from this base class will have it's update function called from
	//world's GameLoop() function which iterates over a collection of objects each frame.
	virtual void Update() = 0;

	void AnotherFunc(); //TODO: Eventually have an actual default function for Entity to make it abstract

	BlazeFramework::Math::Vector2D GetPosition() const { return position; }

protected:
	std::unique_ptr<Graphics> graphics;

	BlazeFramework::Math::Vector2D velocity;
	BlazeFramework::Math::Vector2D position;
};

