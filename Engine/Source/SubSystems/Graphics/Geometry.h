#pragma once
#include "Universal/DataStructures/Vector.h"
#include "Math/Vector3D.h"
#include "Universal/UniversalTypeDefs.h"

namespace BlazeGraphics
{
	class Geometry
	{
	public:
		Vector<BlazeFramework::Vector3D> vertices;
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