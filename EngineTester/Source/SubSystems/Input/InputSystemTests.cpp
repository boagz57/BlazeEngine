#pragma once
#include "gtest/gtest.h"
#include <memory>
#include "Input/InputSystem.h"

//Setup objects to be used in all tests
struct InputSystemTest : public testing::Test
{
	std::unique_ptr<InputSystem> input;

	InputSystemTest() :
		input(new InputSystem)
	{}
};

TEST_F(InputSystemTest, DoesInputSystemInitializeProperly_ExpectTrue)
{
	EXPECT_TRUE(input->Initialize());
}

TEST_F(InputSystemTest, DoesInputSystemShutdownProperly_ExpectTrue)
{
	EXPECT_TRUE(input->Shutdown());
}