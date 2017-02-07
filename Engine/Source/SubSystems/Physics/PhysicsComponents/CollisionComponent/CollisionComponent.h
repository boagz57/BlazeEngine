#pragma once
#include "SubSystems/Component.h"
#include "Math/Vector2D/Vector2D.h"

namespace BlazeGameWorld { class Entity; }

namespace BlazePhysics
{
	struct BoundingBox
	{
		//Bottom left corner of box
		BlazeFramework::Math::Vector2D min;
		//Top right corner of box
		BlazeFramework::Math::Vector2D max;
	};

	class CollisionComponent : public Component
	{
	public:

	protected:

	private:
		BlazeGameWorld::Entity* p_entity;
		BoundingBox collisionBox;

		BlazeFramework::Math::Vector2D velocity;

		///////////////////////////////////////////////////////////////

	public:
		CollisionComponent();
		~CollisionComponent();

		bool Initialize(BlazeGameWorld::Entity* entity) override;
		bool Shutdown();

		void Update() override;

		void CheckForCollision(BoundingBox otherCollisionBox);

		BlazePhysics::BoundingBox GetCollisionBox() const { return collisionBox; }

	protected:
		
	private:
	};
}
