#include "gtest/gtest.h"
#include "Universal/UniversalTypeDefs.h"
#include "Graphics/ShapeData.h"
#include "Math/Vector3D.h"

TEST(ShapeDataTest, DoesTriangleMethodReturnProperAmountOfVertices_Expect3Verts)
{
	sizeofobject numberOfTriangleVerts = (BGraphics::ShapeData::Triangle().vertices.size());
	EXPECT_EQ(numberOfTriangleVerts, 3);
}

TEST(ShapeDataTest, DoesSquareMethodReturnProperAmountOfVertices_Expect4Verts)
{
	sizeofobject numberOfTriangleVerts = (BGraphics::ShapeData::Square().vertices.size());
	EXPECT_EQ(numberOfTriangleVerts, 4);
}