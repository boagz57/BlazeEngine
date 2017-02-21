#pragma once
#include "Math/Vector3D.h"
#include "Universal/UniversalTypeDefs.h"

struct Position
{
public:
	BlazeFramework::Vector3D GetPosition() const { return position; }
	void SetPosition(BlazeFramework::Vector3D newPosition) { position = newPosition; }

private:
	BlazeFramework::Vector3D position{ 0.0f, 0.0f, 0.0f };
};