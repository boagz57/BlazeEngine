#include "gtest/gtest.h"
#include "Graphics/Graphics.h"

TEST(myCat, TestName)
{
	int i = 0;
	EXPECT_TRUE(i == 0);
}

TEST(GraphicsTest, GraphicsSystemTest)
{
	BlazeGraphics::Graphics graphics;
	EXPECT_TRUE(graphics.Initialize());
}