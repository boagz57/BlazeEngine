#include "Precompiled.h"
#include "SDL_mixer.h"
#include "Universal/Macro.h"
#include "GameWorld/SceneManager.h"
#include "Components/Component.h"
#include "Components/Velocity.h"
#include "AudioSystem.h"

/*	void SoundEffect::PlaySoundEffect(uint16 loops default val = 0)
	{
		if (Mix_PlayChannel(loops, soundFile, loops) == -1)
			LOG("SDL_Mixer PlayChannel error: %s", Mix_GetError());
	} */


/* SoundEffect AudioSystem::LoadSoundEffect(char8* filePathToSoundEffect)
{
	auto it = soundEffectCache.find(filePathToSoundEffect);

	SoundEffect effect;

	if (it == soundEffectCache.end())
	{
		//Failed to find effect file path, have to load it
		Mix_Chunk* soundFile = Mix_LoadWAV(filePathToSoundEffect);

		if (soundFile == nullptr)
			LOG("ERROR: Failed to load sound file!!");

		effect.soundFile = soundFile;
		//Cache sound file in map data structure at file path name
		soundEffectCache[filePathToSoundEffect] = soundFile;
	}
	else
	{
		//Already cached
		effect.soundFile = it->second;
	};

	return effect;
} */

static Velocity* entityVelocity = nullptr;

namespace BAudio
{
	static uint16 const numMaxSoundsPending = 116;
	static SoundMessage oldPendingSoundRequests[numMaxSoundsPending] = {};

	uint16 AudioSystem::numSoundsPending = 0;
	SoundMessage AudioSystem::pendingSoundRequests[numMaxSoundsPending] = {};

	AudioSystem::AudioSystem()
	{
	}

	AudioSystem::~AudioSystem()
	{
	}

	bool AudioSystem::Initialize()
	{
		return false;
	}

	bool AudioSystem::Shutdown()
	{
		return false;
	}

	void AudioSystem::Update()
	{
		for (int i = 0; i < numSoundsPending; i++)
		{
			if (oldPendingSoundRequests[i].id == pendingSoundRequests[i].id)
			{
			}
			else
			{
				LOG("Sound %i", pendingSoundRequests[i].id);
			};
		}

		for (int i = 0; i < 2; i++)
		{
			oldPendingSoundRequests[i].id = pendingSoundRequests[i].id;
			pendingSoundRequests[i].id = 0;
		}
		
		numSoundsPending = 0;
	}

	void AudioSystem::PlaySound(uint16 soundID)
	{
		RUNTIME_ASSERT(numSoundsPending != numMaxSoundsPending, "ERROR: Too many sounds in Audio systems' sound queue!");

		pendingSoundRequests[numSoundsPending].id = soundID;

		numSoundsPending++;
	}
}