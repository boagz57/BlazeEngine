#pragma once
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include "../Framework/LowLevelWindow/WindowHandling.h"

namespace BInput { class InputSystem; }

namespace BGraphics
{
	class Window
	{
	public:

	protected:

	private:
		const uint16 cHeight = 0;
		const uint16 cWidth = 0;
		const char8* cpTitle = nullptr;

		//InputSystem needs access to private window member
		friend class BInput::InputSystem;
		BlazeFramework::WindowHandling::BlazeWindow* m_window;

		//////////////////////////////////////////////////////////////////////

	public:
		Window(uint16 width, uint16 height, char8* title);
		~Window();

		void Update();
		void Clear() const;
		bool Closed() const;

		//According to Scott Meyer's Modern Effective C++ book, having copy and = operator functions
		//public and equal to delete produce more descriptive error messages than just the normal
		//empty body (Window(const Window& copy) {}) under private 
		Window(const Window& copy) = delete;
		void operator=(const Window& copy) = delete;

	protected:

	private:
	};
}
