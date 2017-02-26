#pragma once

class SceneManger;

namespace BAudio
{
	class AudioSystem
	{
	public:
		AudioSystem();
		~AudioSystem();

		bool Initialize();
		bool Shutdown();

		void Update(SceneManager& scene);
	};
}