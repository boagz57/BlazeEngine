#pragma once
#include "Universal/UniversalTypeDefs.h"
#include <memory>
#include "Math/Vector2D/Vector2D.h"
#include "DataStructures/Vector/Vector.h"

namespace BlazeGraphics
{
	class Renderer;
}

namespace BlazeInput
{
	class Input;
}

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool Initialize(sfloat velocity, BlazeFramework::Math::Vector2D startPosition) = 0;
	virtual bool Shutdown() = 0;

	//Every object which inherits from this base class will have it's update function called from
	//world's GameLoop() function which iterates over a collection of objects each frame.
	virtual void Update() = 0;

	void AnotherFunc(); //TODO: Eventually have an actual default function for Entity to make it abstract

	BlazeFramework::Math::Vector2D GetPosition() const { return position; }

	BlazeFramework::Math::Vector2D velocity;

protected:
	std::unique_ptr<BlazeGraphics::Renderer> graphics;
	std::unique_ptr<BlazeInput::Input> input;

	BlazeFramework::Math::Vector2D position;
};

