#pragma once
#include "GL/glew.h"
#include "Universal/UniversalTypeDefs.h"
#include "Math/Vector2D/Vector2D.h"
#include "Graphics/Renderable.h"
#include "Graphics/Geometry.h"
#include "DataStructures/Vector/Vector.h"
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeGraphics
{
	class Graphics
	{
	public:
		Graphics();
		~Graphics();

		bool Initialize();
		bool Shutdown();

		void InitializeBuffers();
		void Update(Entity& entity);

		void addGeometry(Geometry geometry);
		void CreateRenderable();

	private:
		static const uint16 cMaxBufferSize = 1024;
		GLuint vertexBufferID;
		GLuint indexBufferID;

		Geometry mesh;
		Renderable renderable;

		Vector<BlazeFramework::Math::Vector2D> transformedVerts;
	};
}