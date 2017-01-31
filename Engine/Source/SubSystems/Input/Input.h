#pragma once

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

		uint16 PollInput();

	protected:

	private:
	};
}


