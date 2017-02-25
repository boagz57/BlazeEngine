#pragma once
#include "gtest/gtest.h"
#include "GameWorld/World.h"

//Setup objects to be used in all tests
struct WorldTest : public testing::Test
{
	World gameWorld;
};

TEST_F(WorldTest, DoesWorldInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(gameWorld.Initialize());
}

TEST_F(WorldTest, DoesWorldShutdownProperly_ExpectTrue)
{
	EXPECT_TRUE(gameWorld.Shutdown());
}