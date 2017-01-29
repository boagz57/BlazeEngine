#include "gtest/gtest.h"
#include "Graphics/Graphics.h"

TEST(GraphicsTest, InitializeFunction)
{
	BlazeGraphics::Graphics graphics;
	graphics.Initialize();
}
