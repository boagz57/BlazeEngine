#include "Precompiled.h"
#include "Graphics/Graphics.h"
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
	Audio::PlaySound("1\n", 3);
	Audio::PlaySound("2\n", 3);
	Audio::PlaySound("3\n", 3);
	Audio::PlaySound("4\n", 3);
	Audio::PlaySound("5\n", 3);
}

void Traingle1::Initialize()
{
	graphics->InitializeBuffers();
}
