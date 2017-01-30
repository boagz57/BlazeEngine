#pragma once
#include <memory>
#include "Input/Controller.h"
#include "Universal/UniversalTypeDefs.h"
#include "Math/Vector2D/Vector2D.h"
#include "DataStructures/Vector/Vector.h"

namespace BlazeGraphics{ class Graphics; }
namespace BlazeInput{ class Input; }
namespace BlazePhysics{ class Physics; }

namespace BlazeGameWorld
{
	class Entity
	{
	public:
		Entity();
		~Entity();

		virtual bool Initialize(BlazeFramework::Math::Vector2D startPosition) = 0;
		virtual bool Shutdown() = 0;

		//Every object which inherits from this base class will have it's update function called from
		//world's GameLoop() function which iterates over a collection of objects each frame.
		virtual void Update() = 0;

		void AnotherFunc(); //TODO: Eventually have an actual default function for Entity to make it abstract

		BlazeFramework::Math::Vector2D GetPosition() const { return position; }

		BlazeFramework::Math::Vector2D velocity;

	protected:
		Entity(BlazeGraphics::Graphics* renderer, BlazeInput::Input* input, BlazePhysics::Physics* physics, BlazeInput::Controller* controller);

		BlazeGraphics::Graphics* renderer;
		BlazeInput::Input* input;
		BlazePhysics::Physics* physics;
		BlazeInput::Controller* controller;

		//So physics can gain access to position since physics needs to be able to modify position
		friend class BlazePhysics::Physics;
		BlazeFramework::Math::Vector2D position;
	};
}
