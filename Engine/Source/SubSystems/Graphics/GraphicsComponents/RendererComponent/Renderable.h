#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"

namespace BlazeGraphics
{
	class Renderable
	{
	public:
		BlazeFramework::Math::Vector2D location;

	protected:

	private:
		friend class RendererComponent;
		Geometry mesh;

		////////////////////////////////////////////////////////////////////////////////

	public:
		Renderable();
		~Renderable();

	private:
	};
}

