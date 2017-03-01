#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "SceneManager.h"
#include "Physics/MovementSystem.h"
#include "Physics/CollisionSystem.h"
#include "Input/InputSystem.h"
#include "Graphics/RenderSystem.h"
#include "Audio/AudioSystem.h"
#include "Universal/DataStructures/Vector.h"
#include <Array>

class World
{
public:

protected:

private:
	//////////////////////////////////////////////////////////////////

public:
	World();
	~World();

	bool Initialize(SceneManager& scene);
	bool Shutdown(SceneManager& scene);

	void GameLoop(SceneManager& scene);

protected:

private:
	BPhysics::MovementSystem movement;
	BInput::InputSystem input;
	BPhysics::CollisionSystem collision;
	BGraphics::RenderSystem renderer;
	BAudio::AudioSystem audio;
};

