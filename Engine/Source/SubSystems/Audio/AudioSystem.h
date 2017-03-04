#pragma once
#include <map>
#include "Universal/DataStructures/Array.h"
#include "SDL_mixer.h"
#include "Universal/UniversalTypeDefs.h"
#include "Components/Component.h"

class SceneManger;

namespace BAudio
{
	struct SoundMessage
	{
		uint16 id;
	};

	class AudioSystem
	{
	public:
		AudioSystem();
		~AudioSystem();

		bool Initialize();
		bool Shutdown();

		void Update();

		static void PlaySound(uint16 soundID);

	private:
		//Used to store all sound files loaded by user
		std::map<char8*, Mix_Chunk*> soundEffectCache;

		std::map<uint16, Mix_Chunk*> sounds;
		static uint16 numSoundsPending;
		static SoundMessage pendingSoundRequests[];
	};
}