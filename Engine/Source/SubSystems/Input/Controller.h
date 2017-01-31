#pragma once
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeInput
{
	class Controller
	{
	public:
		Controller();
		~Controller();

		virtual bool Initialize() = 0;
		virtual bool Shutdown() = 0;

		virtual void Update(BlazeGameWorld::Entity& entity) = 0;

	protected:

	private:

		///////////////////////////////////////////////////////////////////////////////////

	public:

	protected:

	private:
	};
}
