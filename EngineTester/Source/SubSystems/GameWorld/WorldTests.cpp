#pragma once
#include "gtest/gtest.h"
#include "GameWorld/World.h"

TEST(GameWorldSubSystem, WorldClass)
{
	World gameWorld;
	EXPECT_TRUE(gameWorld.Initialize());
	EXPECT_TRUE(gameWorld.Shutdown());
}