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
		//static functions used in BindMovement function in input to bind movement to a key press
		static void MoveUp();
		static void MoveDown();
		static void MoveLeft();
		static void MoveRight();

	private:

		///////////////////////////////////////////////////////////////////////////////////

	public:

	protected:

	private:
	};
}
