#include "Precompiled.h"
#include "Graphics/Graphics.h"
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
	graphics->InitializeBuffers();
}