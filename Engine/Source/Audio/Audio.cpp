#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Audio.h"

uint16 Audio::numberPending = 0;
PlayMessage Audio::pending[];

void Audio::PlaySound(char* message, int16 volume)
{
	RUNTIME_ASSERT(numberPending < MAX_PENDING, "number of pending audio messages exceeds max amount allowed!!");

	pending[numberPending].message = message;
	pending[numberPending].volume = volume;

	numberPending++;
}

void Audio::Update()
{
	for (int i = 0; i < numberPending; i++)
	{
		LOG("%s", pending[i].message);
	}

	numberPending = 0;
}
