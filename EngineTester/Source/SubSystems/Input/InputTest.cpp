#include "gtest/gtest.h"
#include "Input/Input.h"

TEST(InputSubSystem, InputClass)
{
	BlazeInput::Input input;
	EXPECT_TRUE(input.Initialize());
	EXPECT_TRUE(input.Shutdown());
}