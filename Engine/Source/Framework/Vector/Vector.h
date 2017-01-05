#pragma once
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include <vector>

namespace BlazeFramework
{
	//C++11's way of typedef'ing with 'using'
	template<typename type>
	using Vector = std::vector<type>;
};