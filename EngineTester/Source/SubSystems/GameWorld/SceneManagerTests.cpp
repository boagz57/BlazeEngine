#include "gtest/gtest.h"
#include <memory>
#include "GameWorld/SceneManager.h"

struct SceneManagerTest : public ::testing::Test
{
	SceneManager scene;
};

TEST_F(SceneManagerTest, DoesSceneManagerInitializeProperly_ExptectTrue)
{
	EXPECT_TRUE(scene.Initialize());
}

TEST_F(SceneManagerTest, DoesSceneManagerShutdownProperly_ExpectTrue)
{
	EXPECT_TRUE(scene.Shutdown());
}