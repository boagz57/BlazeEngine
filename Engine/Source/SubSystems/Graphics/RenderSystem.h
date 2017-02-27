#pragma once
#include "GL/glew.h"
#include "Components/Component.h"
#include "Universal/DataStructures/Vector.h"
#include "Math/Vector3D.h"

//Adding what components the system requires in order to process information
#define RENDER_MASK (PositionComponent)

class SceneManager;

namespace BGraphics
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