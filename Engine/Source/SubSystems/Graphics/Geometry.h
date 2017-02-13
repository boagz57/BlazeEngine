#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

namespace BlazeGraphics
{
	class Geometry
	{
	public:
		Vector<BlazeFramework::Math::Vector2D> vertices;
		Vector<uint16> indicies;

	protected:

	private:
		friend class ShapeData;

		uint16 numVerts;
		uint16 numIndicies;
		uint renderMode;

		//////////////////////////////////////////////////////////////////////

	public:
		Geometry();
		~Geometry();

	protected:

	private:
	};
}