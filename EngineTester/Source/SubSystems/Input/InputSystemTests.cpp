#pragma once
#include "gtest/gtest.h"
#include "Input/InputSystem.h"

//Setup objects to be used in all tests
struct InputSystemTest : public testing::Test
{
	BInput::InputSystem input;
};

TEST_F(InputSystemTest, DoesInputSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(input.Initialize());
}

TEST_F(InputSystemTest, DoesInputSystemShutdownProperly_ExpectTrue)
{
	EXPECT_TRUE(input.Shutdown());
}