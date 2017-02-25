#include "gtest/gtest.h"
#include "GameWorld/SceneManager.h"
#include "Physics/MovementSystem.h"

//Setup objects to be used in all tests
struct MovementSystemTest: public testing::Test
{
	BPhysics::MovementSystem movementSystem;
};

TEST_F(MovementSystemTest, DoesMovementSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(movementSystem.Initialize());
}

TEST_F(MovementSystemTest, DoesMovementSystemShutdownProperly_ExpectTrue)
{
	EXPECT_TRUE(movementSystem.Shutdown());
}