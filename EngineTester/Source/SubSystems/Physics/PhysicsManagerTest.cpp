#include "gtest/gtest.h"
#include "Physics/PhysicsManager.h"

TEST(PhsyicsSubSystem, PhysicsClass)
{
	BlazePhysics::PhysicsManager physics;
	EXPECT_TRUE(physics.Initialize());
	EXPECT_TRUE(physics.Shutdown());
}