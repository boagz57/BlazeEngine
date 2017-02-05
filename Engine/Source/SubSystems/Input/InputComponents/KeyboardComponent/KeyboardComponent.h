#pragma once
#include "SubSystems/Component.h"
#include "LowLevelInput/KeyboardHandling.h"

namespace BlazeGameWorld { class Entity; }

namespace BlazeInput
{
	class KeyboardComponent : public Component
	{
	public:

	protected:

	private:
		BlazeGameWorld::Entity* p_entity;

		////////////////////////////////////////////////////////////////////////////

	public:
		KeyboardComponent();
		~KeyboardComponent();

		bool Initialize(BlazeGameWorld::Entity* p_entity);
		bool Shutdown();

		void Update() override;

	protected:

	private:
	};
}


