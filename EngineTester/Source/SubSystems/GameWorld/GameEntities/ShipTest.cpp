#include "gtest/gtest.h"
#include "Math/Vector2D/Vector2D.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "GameWorld/Player.h"

TEST(GameWorldSubSystem, ShipClass)//TODO: setup to test initialize and shutdown functions 
{
	BlazeGameWorld::Player ship;
	EXPECT_TRUE(ship.Initialize(BlazeFramework::Math::Vector2D(0.0f, 1.0f), BlazeGraphics::ShapeData::Triangle()));
}
