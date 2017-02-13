#pragma once
#include "Universal/UniversalTypeDefs.h"
#define MAX_PENDING 16

struct PlayMessage
{
	char* message;
};

class Audio
{
public:
	void Initialize();
	void Update();

private:
	int16 numberPending;
	PlayMessage pending[MAX_PENDING];
};

