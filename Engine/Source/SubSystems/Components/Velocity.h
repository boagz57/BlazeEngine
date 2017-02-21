#pragma once
#include "Math/Vector3D.h"
#include "Universal/UniversalTypeDefs.h"

struct Velocity
{
public:
	inline BlazeFramework::Vector3D GetVelocity() const { return velocity; }
	inline void SetVelocity(BlazeFramework::Vector3D newVelocity) { velocity = newVelocity; }
	inline void SetVelocityX(sfloat newVelocityX) { velocity.x = newVelocityX; }
	inline void SetVelocityY(sfloat newVelocityY) { velocity.y = newVelocityY; }

private:
	BlazeFramework::Vector3D velocity{ 0.0f, 0.0f, 0.0f };
};
