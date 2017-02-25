#pragma once
#include "Components/Component.h"

class SceneManager;

#define INPUT_MASK (VelocityComponent)

namespace BInput
{
	class InputSystem
	{
	public:
		InputSystem();
		~InputSystem();

		bool Initialize();
		bool Shutdown();

		void Update(SceneManager& scene);
	};
}