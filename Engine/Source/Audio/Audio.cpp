#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Audio.h"

PlayMessage Audio::pending[];
int16 Audio::numberPending;

void Audio::Initialize()
{
	for (int i = 0; i < MAX_PENDING; i++)
	{
		pending[i].message = nullptr;
		pending[i].volume = 0;
	}

	numberPending = 0;
}

void Audio::PlaySound(char* message, int16 volume)
{
	RUNTIME_ASSERT(numberPending < MAX_PENDING, "ERROR: number of pending elements is more than array can hold!");

	pending[numberPending].message = message;
	pending[numberPending].volume = volume;

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
