#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"

namespace BlazeGraphics
{
	class GraphicsManager
	{
	public:

	protected:

	private:
		static uint16 numGraphicsComponents;
		Vector<BlazeGraphics::RendererComponent> graphicsComponents;

		/////////////////////////////////////////////////

	public:
		GraphicsManager();
		~GraphicsManager();

		template <typename GraphicsComponentType>
		GraphicsComponentType* CreateGraphicsComponent();

	private:
	};

	template<typename GraphicsComponentType>
	GraphicsComponentType* GraphicsManager::CreateGraphicsComponent()
	{
		GraphicsComponentType graphicsComponent;
		graphicsComponents.push_back(graphicsComponent);

		return &graphicsComponents.at(numGraphicsComponents++);
	}
}