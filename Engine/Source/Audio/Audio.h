#pragma once
#include "Universal/UniversalTypeDefs.h"
#define MAX_PENDING 16

struct PlayMessage
{
	char* message;
	int16 volume;
};

class Audio
{
public:
	static void PlaySound(char* message, int16 volume);
	static void Update();

private:
	static uint16 numberPending;
	static PlayMessage pending[MAX_PENDING];
};

