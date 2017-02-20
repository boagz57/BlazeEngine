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
			//In order to have triangle centered on it's origin must use pathagoreans theorem on 1st
			//vert to match distance from origin to the other verts. Just did this off site and put in
			//the resulting number.
			BlazeFramework::Vector2D(+0.0f, +0.1414213f), //0
			BlazeFramework::Vector2D(-0.1f, -0.1f),       //1
			BlazeFramework::Vector2D(+0.1f, -0.1f)        //2
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

	BlazeGraphics::Geometry ShapeData::Square()
	{
		Vector<BlazeFramework::Vector2D> squareVerts 
		{
			BlazeFramework::Vector2D(-0.1f, +0.2f),//0
			BlazeFramework::Vector2D(-0.1f, -0.1f), //1
			BlazeFramework::Vector2D(+0.1f, 0.2f), //2
			BlazeFramework::Vector2D(+0.1f, -0.1f)  //3
		};

		Vector<uint16> squareIndices 
		{
			0,1,2,3,1,2
		};

		geometry.numVerts = 4;
		geometry.vertices = squareVerts;
		geometry.numIndicies = 6;
		geometry.indicies = squareIndices;

		return geometry;
	}

}
