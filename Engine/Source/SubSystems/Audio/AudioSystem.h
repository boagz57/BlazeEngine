#pragma once
#include <map>
#include "SDL_mixer.h"
#include "Universal/UniversalTypeDefs.h"
#include "Components/Component.h"

#define AUDIO_MASK (VelocityComponent)

class SceneManger;

namespace BAudio
{
	class SoundEffect
	{
	public:
		void PlaySoundEffect(uint16 loops = 0);

	private:
		friend class AudioSystem;

		Mix_Chunk* soundFile = nullptr;
	};

	class AudioSystem
	{
	public:
		AudioSystem();
		~AudioSystem();

		bool Initialize();
		bool Shutdown();

		void Update(SceneManager& scene);

		SoundEffect LoadSoundEffect(char8* filePathToSoundEffect);

	private:
		//Used to store all sound files loaded by user
		std::map<char8*, Mix_Chunk*> soundEffectCache;
	};
}