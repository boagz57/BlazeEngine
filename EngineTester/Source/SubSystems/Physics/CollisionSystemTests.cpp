#include "gtest/gtest.h"
#include "Physics/CollisionSystem.h"
#include "GameWorld/SceneManager.h"

//Setup objects to be used in all tests
struct CollisionSystemTest : public testing::Test
{
	BPhysics::CollisionSystem collision;
	SceneManager scene;
};

TEST_F(CollisionSystemTest, DoesCollisionSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(collision.Initialize(scene));
}

TEST_F(CollisionSystemTest, DoesCollisionSystemShutdownProperly_ExpectTrue)
{
	EXPECT_TRUE(collision.Shutdown());
}