#pragma once
#include "Sprite.h"

namespace BGraphics
{
	class ShapeData
	{
	public:

	protected:

	private:
		static Sprite sprite;

		///////////////////////////////////////////////////////

	public:
		ShapeData();
		~ShapeData();

		static Sprite Triangle();
		static Sprite Square();

	protected:
		
	private:
	};
}