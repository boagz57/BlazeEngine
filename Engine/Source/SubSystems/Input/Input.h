#pragma once
#include "LowLevelInput/KeyboardHandling.h"
#include <map>

namespace BlazeInput
{
	class Input
	{
	public:

	protected:

	private:
		//Used in Bind function to bind a keyCode with a pointer to a movement function.
		std::map<const uint16, void (*)()> movementKeyBindings;

		////////////////////////////////////////////////////////////////////////////

	public:
		Input();
		~Input();

		bool Initialize();
		bool Shutdown();

		void BindMovement(const uint16 key, void (*pointerToMovementFunc)());
		void Update();

	protected:

	private:
	};
}


