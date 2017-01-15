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
	Audio::PlaySound("hahahah\n", 3);
	Audio::PlaySound("nooooooo\n", 3);
	Audio::PlaySound("yessssss\n", 3);
	Audio::Update();
}

void Traingle1::Initialize()
{
	graphics->InitializeBuffers();
}
