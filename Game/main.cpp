#include "Math/Vector3D.h"
#include "Player.h"
#include "ShapeData.h"
#include "Universal/Globals.h"
#include "Graphics/Window/Window.h"
#include "Graphics/RenderSystem.h"
#include "Universal/UniversalTypeDefs.h"


uint16 main()
{
	RenderSystem::LoadSprite(BGraphics::ShapeData::Triangle());
	Player goku;

	while (!window.Closed())
	{
		window.Clear();

		window.Update();
	}

	return 0;
}