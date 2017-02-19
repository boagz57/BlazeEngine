#pragma once
#include "GL/glew.h"
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D.h"

//Adding what components the system requires in order to process information
#define RENDER_MASK (PositionComponent)

class SceneManager;

namespace BlazeGraphics
{
	class RenderSystem
	{
	public:

	protected:

	private:

		/////////////////////////////////////////////////////////////

	public:
		RenderSystem();
		~RenderSystem();

		bool Initialize(SceneManager& scene);
		bool Shutdown();

		void Update(SceneManager& scene);

	protected:

	private:
	};
}