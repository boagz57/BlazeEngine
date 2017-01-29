#include "gtest/gtest.h"
#include "Graphics/Graphics.h"

TEST(GraphicsSubSystem, GraphicsClass)
{
	BlazeGraphics::Graphics graphics;
	EXPECT_TRUE(graphics.Initialize());
}