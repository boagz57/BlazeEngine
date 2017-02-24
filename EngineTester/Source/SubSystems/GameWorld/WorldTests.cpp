#pragma once
#include "gtest/gtest.h"
#include <memory>
#include "GameWorld/World.h"

//Setup objects to be used in all tests
struct WorldTest : public testing::Test
{
	std::unique_ptr<World> gameWorld;

	WorldTest() :
		gameWorld(new World)
	{}
};

TEST_F(WorldTest, DoesCollisionSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(gameWorld->Initialize());
}
