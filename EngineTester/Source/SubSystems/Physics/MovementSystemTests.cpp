#include "gtest/gtest.h"
#include <memory>
#include "GameWorld/SceneManager.h"
#include "Physics/MovementSystem.h"

//Setup objects to be used in all tests
struct MovementSystemTest: public testing::Test
{
	std::unique_ptr<MovementSystem> movementSystem;

	MovementSystemTest() :
		movementSystem(new MovementSystem)
	{}
};

TEST_F(MovementSystemTest, DoesMovementSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(movementSystem->Initialize());
}