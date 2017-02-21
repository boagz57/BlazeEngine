#pragma once
#include "Universal/UniversalTypeDefs.h"

struct Appearance 
{
public:
	char8* GetShapeName() const { return geometryShapeName; }
	void SetRenderShape(char8* shapeName) { geometryShapeName = shapeName; }

private:
	char8* geometryShapeName;
};
