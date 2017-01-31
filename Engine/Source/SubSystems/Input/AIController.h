#pragma once
#include "Input/Controller.h"
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeInput
{
	class AIController : public Controller
	{
	public:

	protected:

	private:

		///////////////////////////////////////////////////////////////////////////

	public:
		AIController();
		~AIController();

		bool Initialize() override;
		bool Shutdown() override;

		void Update(BlazeGameWorld::Entity& entity) override;

	protected:

	private:
	};
}