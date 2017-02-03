#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Graphics/Geometry.h"
#include "Physics/Physics.h"
#include "Graphics/Graphics.h"
#include "Math/Vector2D/Vector2D.h"
#include "DataStructures/Vector/Vector.h"

namespace BlazeGameWorld
{
	class Entity
	{
	public:
		BlazeFramework::Math::Vector2D velocity;

	protected:
		BlazeGraphics::Graphics renderer;
		BlazePhysics::Physics physics;

		//So physics can gain access to position since physics needs to be able to modify position
		friend class BlazePhysics::Physics;
		BlazeFramework::Math::Vector2D position;

	private:

		///////////////////////////////////////////////////////////////////////

	public:
		Entity();
		~Entity();

		virtual bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry);
		virtual bool Shutdown();

		//Every object which inherits from this base class will have it's update function called from
		//world's GameLoop() function which iterates over a collection of objects each frame.
		virtual void Update() = 0;

		BlazeFramework::Math::Vector2D GetPosition() const { return position; };

	protected:

	private:
	};
}
