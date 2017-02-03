#pragma once
#include "LowLevelInput/KeyboardHandling.h"
#include <map>

namespace BlazeGameWorld { class Entity; }

namespace BlazeInput
{
	class Input
	{
	public:

	protected:

	private:

		////////////////////////////////////////////////////////////////////////////

	public:
		Input();
		~Input();

		bool Initialize();
		bool Shutdown();

		void Update(BlazeGameWorld::Entity& entity);

	protected:

	private:
	};
}


