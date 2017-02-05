#include "gtest/gtest.h"
#include "Input/InputManager.h"

TEST(InputSubSystem, InputClass)
{
	BlazeInput::InputManager input;
	EXPECT_TRUE(input.Initialize());
	EXPECT_TRUE(input.Shutdown());
}