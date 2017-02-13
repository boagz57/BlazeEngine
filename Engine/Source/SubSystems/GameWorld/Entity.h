#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include <memory>
#include "Math/Vector2D/Vector2D.h"
#include "DataStructures/Vector/Vector.h"

class Component;

namespace BlazeGameWorld
{
	class Entity
	{
	public:
		uint16 const entityID;

	protected:

	private:

		///////////////////////////////////////////////////////////////////////

	public:
		Entity(uint16 entityID);
		~Entity();

		virtual bool Initialize(BlazeFramework::Math::Vector2D startPosition);
		virtual bool Shutdown();

		virtual void Update();

	protected:

	private:
	};
}
