#pragma once
#include "gtest/gtest.h"
#include <memory>
#include "GameWorld/SceneManager.h"
#include "Graphics/RenderSystem.h"

//Setup objects to be used in all tests
struct RenderSystemTest : public testing::Test
{
	std::unique_ptr<BlazeGraphics::RenderSystem> renderer;
	std::unique_ptr<SceneManager> scene;

	RenderSystemTest() :
		renderer(new BlazeGraphics::RenderSystem),
		scene(new SceneManager)
	{
		scene->Initialize();
	}
};

TEST_F(RenderSystemTest, DoesRenderSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(renderer->Initialize(*scene));
}