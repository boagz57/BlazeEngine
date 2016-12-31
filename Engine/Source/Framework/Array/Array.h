#pragma once
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include <array>

namespace BlazeFramework
{
	//C++11's way of typedef'ing with 'using'
	template<typename type, uint32 size>
	using Array = std::array<type, size>;
}