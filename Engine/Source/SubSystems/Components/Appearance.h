#pragma once
#include "Universal/UniversalTypeDefs.h"

struct Appearance 
{
public:
	inline uint16 GetSpriteID() const { return spriteID; }
	inline void SetSpriteID(uint16 newSpriteID) { newSpriteID = spriteID; }

private:
	uint16 spriteID;
};
