#include "Precompiled.h"
#include "ShapeData.h"

namespace BGraphics
{
	//static memory
	Sprite ShapeData::sprite;

	ShapeData::ShapeData()
	{}

	ShapeData::~ShapeData()
	{}

	Sprite ShapeData::Triangle()
	{
		Vector<BlazeFramework::Vector3D> triangleVerts
		{
			//In order to have triangle centered on it's origin must use pathagoreans theorem on 1st
			//vert to match distance from origin to the other verts. Just did this off site and put in
			//the resulting number.
			BlazeFramework::Vector3D(+0.0f, +0.1414213f, 0.0f), //0
			BlazeFramework::Vector3D(-0.1f, -0.1f, 0.0f),       //1
			BlazeFramework::Vector3D(+0.1f, -0.1f, 0.0f)        //2
		};

		Vector<uint16> triangleIndicies
		{
			0,1,2
		};

		sprite.numVerts = 3;
		sprite.vertices = triangleVerts;
		sprite.numIndicies = 3;
		sprite.indicies = triangleIndicies;

		return sprite;
	}

	BGraphics::Sprite ShapeData::Square()
	{
		Vector<BlazeFramework::Vector3D> squareVerts 
		{
			BlazeFramework::Vector3D(-0.1f, +0.2f, 0.0f),//0
			BlazeFramework::Vector3D(-0.1f, -0.1f, 0.0f), //1
			BlazeFramework::Vector3D(+0.1f, 0.2f, 0.0f), //2
			BlazeFramework::Vector3D(+0.1f, -0.1f, 0.0f)  //3
		};

		Vector<uint16> squareIndices 
		{
			0,1,2,3,1,2
		};

		sprite.numVerts = 4;
		sprite.vertices = squareVerts;
		sprite.numIndicies = 6;
		sprite.indicies = squareIndices;

		return sprite;
	}

}
