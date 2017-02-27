#include "Precompiled.h"
#include "Input/InputSystem.h"
#include "Graphics/RenderSystem.h"
#include "Physics/MovementSystem.h"
#include "Physics/CollisionSystem.h"
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

bool World::Initialize()
{
	SDL_Init(SDL_INIT_AUDIO);

	//Parameters can be either MIX_INIT_FALC, MIX_INIT_MOD, MIX_INIT_MP3 or MIX_INIT_OGG. These bitwise macro 
	//flags represent the different audio file types SDL_Mixer will support
	if (Mix_Init(MIX_INIT_MP3) == -1)
	{
		LOG("ERROR: SDL_Mixer could not initialize!");
	};


	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		LOG("ERROR: SDL_Mixer Mix_OpenAudio initialize function did not initialize!!");
	};

	return true;
}

bool World::Shutdown()
{
	Mix_Quit();
	SDL_Quit();
	return true;
}

void World::GameLoop()
{
	BPhysics::MovementSystem movement;
	BInput::InputSystem input;
	BPhysics::CollisionSystem collision;
	BGraphics::RenderSystem renderer;

	SceneManager scene;
	scene.Initialize();

	scene.CreatePlayer(BlazeFramework::Vector3D(0.0f, 0.0f, 0.0f), "Triangle");
	scene.CreateStaticEntity(BlazeFramework::Vector3D(0.0f, 0.4f, 0.0f), "Square");
	scene.CreateStaticEntity(BlazeFramework::Vector3D(0.4f, 0.4f, 0.0f), "Triangle");

	input.Initialize();
	movement.Initialize();
	collision.Initialize(scene);
	renderer.Initialize(scene);

	MyOpenGL::InstallShaders();

	engineClock.Initialize();

	while (!window.Closed())
	{
		window.Clear();
		engineClock.NewFrame();

		input.Update(scene);
		movement.Update(scene);
		collision.Update(scene);
		renderer.Update(scene);

		window.Update();
	};
}