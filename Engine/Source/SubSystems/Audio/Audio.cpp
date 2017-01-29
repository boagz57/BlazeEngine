#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Audio.h"

void Audio::Initialize()
{
	for (int i = 0; i < MAX_PENDING; i++)
	{
		pending[i].message = nullptr;
	}

	numberPending = 0;
}

void Audio::PlaySound(char* message, BlazeGameWorld::Entity& obj)
{
	RUNTIME_ASSERT(numberPending < MAX_PENDING, "ERROR: number of pending elements is more than array can hold!");

	pending[numberPending].message = message;

	numberPending++;
}

void Audio::Update()
{
	for (int i = 0; i < numberPending; i++)
	{
		LOG("%s", pending[i].message);
	};

	numberPending = 0;
}
