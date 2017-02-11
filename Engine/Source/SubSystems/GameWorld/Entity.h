#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include "Graphics/GraphicsManager.h"
#include "Physics/PhysicsManager.h"
#include <memory>
#include "Math/Vector2D/Vector2D.h"
#include "DataStructures/Vector/Vector.h"

class Component;

namespace BlazeGameWorld
{
	class Entity
	{
	public:
		uint16 const EntityID;
		BlazeFramework::Math::Vector2D position;

	protected:
		Vector<Component*> components;

	private:

		///////////////////////////////////////////////////////////////////////

	public:
		Entity(uint16 ID);
		~Entity();

		virtual bool Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry, BlazePhysics::PhysicsManager& physManager, BlazeGraphics::GraphicsManager& grphsManager);
		virtual bool Shutdown();

		//Every object which inherits from this base class will have it's update function called from
		//world's GameLoop() function which iterates over a collection of objects each frame.
		virtual void Update() = 0;

	protected:

	private:
	};
}
