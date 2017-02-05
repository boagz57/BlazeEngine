#pragma once
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

namespace BlazeGraphics
{
	class Geometry
	{
	public:

	protected:

	private:
		friend class RendererComponent;
		friend class ShapeData;

		uint16 numVerts;
		Vector<BlazeFramework::Math::Vector2D> vertices;
		uint16 numIndicies;
		Vector<uint16> indicies;
		uint renderMode;

		//////////////////////////////////////////////////////////////////////

	public:
		Geometry();
		~Geometry();

	protected:

	private:
	};
}