#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

namespace BlazeGraphics
{
	class Geometry
	{
	public:
		Geometry();
		~Geometry();

	private:
		friend class Graphics;
		friend class ShapeData;

		uint16 numVerts;
		Vector<BlazeFramework::Math::Vector2D> vertices;
		uint16 numIndicies;
		Vector<uint16> indicies;
		uint renderMode;
	};
}