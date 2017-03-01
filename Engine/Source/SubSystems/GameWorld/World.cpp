#include "Precompiled.h"
#include "Input/InputSystem.h"
#include "Graphics/RenderSystem.h"
#include "Physics/MovementSystem.h"
#include "Physics/CollisionSystem.h"
#include "Audio/AudioSystem.h"
#include "GameWorld/SceneManager.h"
#include "SDL/SDL.h"
#include "SDL_mixer.h"
#include "Framework/LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Universal/Globals.h"
#include "World.h"

World::World()
{}

World::~World()
{}

bool World::Initialize(SceneManager& scene)
{
	SDL_Init(SDL_INIT_AUDIO);

	//Parameters can be either MIX_INIT_FALC, MIX_INIT_MOD, MIX_INIT_MP3 or MIX_INIT_OGG. These bitwise macro 
	//flags represent the different audio file types SDL_Mixer will support
	if (Mix_Init(MIX_INIT_MP3) == 0)
	{
		LOG("ERROR: SDL_Mixer error: %s", Mix_GetError());
	};


	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		LOG("ERROR: SDL_Mixer OpenAudio function error: %s", Mix_GetError());
	};

	input.Initialize();
	movement.Initialize();
	audio.Initialize();
	collision.Initialize(scene);
	renderer.Initialize(scene);


	return true;
}

bool World::Shutdown(SceneManager& scene)
{
	Mix_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	return true;
}

void World::GameLoop(SceneManager& scene)
{

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		input.Update(scene);
		movement.Update(scene);
		audio.Update(scene);
		collision.Update(scene);
		renderer.Update(scene);

		window.Update();
	};
}