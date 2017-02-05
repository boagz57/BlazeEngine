#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "GameWorld/Entity.h"
#define MAX_PENDING 16

struct PlayMessage
{
	char* message;
};

class Audio
{
public:
	void Initialize();
	void PlaySound(char* message, BlazeGameWorld::Entity& obj);
	void Update();

private:
	int16 numberPending;
	PlayMessage pending[MAX_PENDING];
};

