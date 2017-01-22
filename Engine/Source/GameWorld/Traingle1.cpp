#include "Precompiled.h"
#include "Graphics/Graphics.h"
#include "Graphics/Geometry.h"
#include "Audio/Audio.h"
#include "Traingle1.h"


Traingle1::Traingle1()
{
}

Traingle1::~Traingle1()
{
}

void Traingle1::Update()
{
	graphics->Update(*this);
}

void Traingle1::Initialize()
{
	Geometry* triangleMesh = graphics->addGeometry(3, triangleVerts, 3, triangleIndicies);
	graphics->addRenderable(triangleMesh);
	graphics->InitializeBuffers();
}
