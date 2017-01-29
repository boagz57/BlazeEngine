#pragma once
#include "Math/Vector2D/Vector2D.h"
#include "Graphics/Geometry.h"

namespace BlazeGraphics
{
	class Renderable
	{
	public:
		Renderable();
		~Renderable();

		BlazeFramework::Math::Vector2D location;

	private:
		friend class Graphics;
		Geometry mesh;
	};
}

