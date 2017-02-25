#pragma once

class SceneManger;

class AudioSystem
{
public:
	AudioSystem();
	~AudioSystem();

	bool Initialize();
	bool Shutdown();

	void Update(SceneManager& scene);
};