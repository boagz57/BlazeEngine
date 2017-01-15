#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Audio.h"

PlayMessage Audio::pending[];
uint16 Audio::mHead;
uint16 Audio::mTail;

void Audio::Initialize()
{
	for (int i = 0; i < MAX_PENDING; i++)
	{
		pending[i].message = nullptr;
		pending[i].volume = 0;
	}

	mHead = 0;
	mTail = 0;
}

void Audio::PlaySound(char* message, int16 volume)
{
	RUNTIME_ASSERT((mTail + 1) % MAX_PENDING != mHead, "number of pending audio messages exceeds max amount allowed!!");

	pending[mTail].message = message;
	pending[mTail].volume = volume;

	//Wrap tail around to 0 if it reaches end of array
	mTail = (mTail + 1) % MAX_PENDING;
}

void Audio::Update()
{
	//If the ring buffer is empty then do nothing and return from function
	if (mHead == mTail) return;

	LOG("%s", pending[mHead].message);

	//Wrap head back around to 0 if it reaches end of array
	mHead = (mHead + 1) % MAX_PENDING;
}
