#pragma once
#include "Math/Vector2D.h"
#include "Graphics/Geometry.h"

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

