#include "Precompiled.h"
#include "Triangle.h"

bool Triangle::Initialize()
{
	mGraphics.InitializeBuffers();
	return true;
}

void Triangle::Update()
{
	mGraphics.Draw();
}
