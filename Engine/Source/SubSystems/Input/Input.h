#pragma once

namespace BlazeInput
{
	class Input
	{
	public:
		Input();
		~Input();

		bool Initialize();
		bool Shutdown();

		uint16 PollInput();
	};
}


