#include "Graphics/Geometry.h"

class ShapeData
{
public:
	ShapeData();
	~ShapeData();

	static Geometry Triangle();

private:
	static Geometry geometry;
};