#pragma once
#include "Math/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"

struct Velocity
{
public:
	BlazeFramework::Vector2D GetVelocity() const { return velocity; }
	void SetVelocity(BlazeFramework::Vector2D newVelocity) { velocity = newVelocity; }
	void SetVelocityX(sfloat newVelocityX) { velocity.x = newVelocityX; }
	void SetVelocityY(sfloat newVelocityY) { velocity.y = newVelocityY; }

private:
	BlazeFramework::Vector2D velocity{ 0.0f, 0.0f };
};
