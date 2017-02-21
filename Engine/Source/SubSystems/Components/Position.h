#pragma once
#include "Math/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

struct Position
{
public:
	BlazeFramework::Vector2D GetPosition() const { return position; }
	void SetPosition(BlazeFramework::Vector2D newPosition) { position = newPosition; }

private:
	BlazeFramework::Vector2D position{ 0.0f, 0.0f };
};