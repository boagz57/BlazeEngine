#pragma once
#include "LowLevelInput/KeyboardHandling.h"

namespace BlazeGameWorld { class Entity; }

namespace BlazeInput
{
	class InputManager 
	{
	public:

	protected:

	private:

		////////////////////////////////////////////////////////////////////////////

	public:
		InputManager();
		~InputManager();

		bool Initialize();
		bool Shutdown();

		void Update();

	protected:

	private:
	};
}


