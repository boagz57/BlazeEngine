#pragma once
#include "gtest/gtest.h"
#include "GameWorld/SceneManager.h"
#include "Graphics/RenderSystem.h"

//Setup objects to be used in all tests
struct RenderSystemTest : public testing::Test
{
	BGraphics::RenderSystem renderer;
	SceneManager scene;
};

TEST_F(RenderSystemTest, DoesRenderSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(renderer.Initialize(scene));
}

TEST_F(RenderSystemTest, DoesRenderSystemShutdownProperly_ExpectTrue)
{
	EXPECT_TRUE(renderer.Shutdown());
}