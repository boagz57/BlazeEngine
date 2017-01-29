#include "gtest/gtest.h"
#include "Physics/Physics.h"

TEST(PhsyicsSubSystem, PhysicsClass)
{
	BlazePhysics::Physics physics;
	EXPECT_TRUE(physics.Initialize());
	EXPECT_TRUE(physics.Shutdown());
}