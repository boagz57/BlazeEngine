#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Graphics/GraphicsComponents/RendererComponent/Geometry.h"
#include "PhysicsComponents/CollisionComponent/CollisionComponent.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "Math/Vector2D/Vector2D.h"
#include "DataStructures/Vector/Vector.h"

namespace BlazeGameWorld
{
	class Entity
	{
	public:
		BlazeFramework::Math::Vector2D velocity;

	protected:
		BlazeGraphics::RendererComponent renderer;
		BlazePhysics::CollisionComponent collision;

		//So physics can gain access to position since physics needs to be able to modify position
		friend class BlazePhysics::CollisionComponent;
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

		BlazePhysics::CollisionComponent* GetPhysicsComponent() { return &collision; };
	protected:

	private:
	};
}
