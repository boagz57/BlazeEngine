#pragma once
#include "Math/Vector3D.h"
#include "Universal/UniversalTypeDefs.h"

struct Position
{
public:
	inline BlazeFramework::Vector3D GetPosition() const { return position; }
	inline void SetPosition(BlazeFramework::Vector3D newPosition) { position = newPosition; }

private:
	BlazeFramework::Vector3D position{ 0.0f, 0.0f, 0.0f };
};