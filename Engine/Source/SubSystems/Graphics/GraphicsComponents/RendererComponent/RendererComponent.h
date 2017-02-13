#pragma once
#include "GL/glew.h"
#include "Universal/UniversalTypeDefs.h"
#include "Math/Vector2D/Vector2D.h"
#include "GraphicsComponents/RendererComponent/Renderable.h"
#include "GraphicsComponents/RendererComponent/Geometry.h"
#include "DataStructures/Vector/Vector.h"

/*namespace BlazeGameWorld { class Entity; }

namespace BlazeGraphics
{
	class RendererComponent : public Component
	{
	public:

	protected:

	private:
		static const uint16 cMaxBufferSize = 1024;
		GLuint vertexBufferID;
		GLuint indexBufferID;

		Geometry mesh;
		Renderable renderable;
		BlazeGameWorld::Entity* p_entity;

		uint16 const c_numTransformedVertices = 3;
		Vector<BlazeFramework::Math::Vector2D> transformedVerts;

		///////////////////////////////////////////////////////////////////////

	public:
		RendererComponent();
		~RendererComponent();

		bool Initialize(BlazeGameWorld::Entity* p_entity);
		bool Shutdown();

		void InitializeBuffers();
		void Update() override;

		void addGeometry(Geometry geometry);
		void CreateRenderable();

	protected:

	private:
	};
}*/