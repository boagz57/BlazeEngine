#pragma once
#include "Entity.h"

//TODO: Make sure to update all header files and make them lean and mean

class Traingle1 : public Entity
{
public:
	Traingle1();
	~Traingle1();

	virtual void Update() override;
	virtual void Initialize() override;

private:
	Vector<BlazeFramework::Math::Vertex3D> triangleVerts
	{
		BlazeFramework::Math::Vertex3D(+0.0f, +0.2f, 0.0f),
		BlazeFramework::Math::Vertex3D(-0.1f, 0.0f, 0.0f),
		BlazeFramework::Math::Vertex3D(+0.1f, 0.0f, 0.0f)
	};

	Vector<uint16> triangleIndicies
	{
		0,1,2
	};
};

