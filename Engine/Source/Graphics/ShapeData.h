#include "Graphics/Geometry.h"

namespace BlazeGraphics
{
	class ShapeData
	{
	public:
		ShapeData();
		~ShapeData();

		static Geometry Triangle();

	private:
		static Geometry geometry;
	};
}