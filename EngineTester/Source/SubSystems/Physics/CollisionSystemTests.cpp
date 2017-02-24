#include "gtest/gtest.h"
#include <memory>
#include "Physics/CollisionSystem.h"
#include "GameWorld/SceneManager.h"

//Setup objects to be used in all tests
struct CollisionSystemTest : public testing::Test
{
	std::unique_ptr<CollisionSystem> collision;
	std::unique_ptr<SceneManager> scene;

	CollisionSystemTest() :
		collision(new CollisionSystem),
		scene(new SceneManager)
	{
		scene->Initialize();
	}
};

TEST_F(CollisionSystemTest, DoesCollisionSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(collision->Initialize(*scene));
}