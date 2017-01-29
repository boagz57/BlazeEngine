#include "gtest/gtest.h"
#include "Math/Vector2D/Vector2D.h"
#include "GameWorld/GameEntities/Ship.h"

TEST(GameWorldSubSystem, ShipClass)//TODO: setup to test initialize and shutdown functions 
{
	BlazeGameWorld::Ship ship;
	EXPECT_TRUE(ship.Initialize(BlazeFramework::Math::Vector2D(0.0f, 1.0f)));
}
