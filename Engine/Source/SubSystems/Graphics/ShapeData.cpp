#include "Precompiled.h"
#include "ShapeData.h"

namespace BlazeGraphics
{
	//static memory
	Geometry ShapeData::geometry;

	ShapeData::ShapeData()
	{}

	ShapeData::~ShapeData()
	{}

	Geometry ShapeData::Triangle()
	{
		Vector<BlazeFramework::Vector2D> triangleVerts
		{
			BlazeFramework::Vector2D(+0.0f, +0.2f),
			BlazeFramework::Vector2D(-0.1f, 0.0f),
			BlazeFramework::Vector2D(+0.1f, 0.0f)
		};

		Vector<uint16> triangleIndicies
		{
			0,1,2
		};

		geometry.numVerts = 3;
		geometry.vertices = triangleVerts;
		geometry.numIndicies = 3;
		geometry.indicies = triangleIndicies;

		return geometry;
	}
}
