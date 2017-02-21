#pragma once
#include "Universal/UniversalTypeDefs.h"

struct Appearance 
{
public:
	inline char8* GetShapeName() const { return geometryShapeName; }
	inline void SetRenderShape(char8* shapeName) { geometryShapeName = shapeName; }

private:
	char8* geometryShapeName;
};
