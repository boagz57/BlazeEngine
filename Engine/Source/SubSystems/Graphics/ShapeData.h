#pragma once
#include "Geometry.h"

namespace BGraphics
{
	class ShapeData
	{
	public:

	protected:

	private:
		static Geometry geometry;

		///////////////////////////////////////////////////////

	public:
		ShapeData();
		~ShapeData();

		static Geometry Triangle();
		static Geometry Square();

	protected:
		
	private:
	};
}