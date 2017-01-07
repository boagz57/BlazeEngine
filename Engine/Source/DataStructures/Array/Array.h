#pragma once
#include "Universal/UniversalTypeDefs.h"
#include <array>

//C++11's way of typedef'ing with 'using'
template<typename type, uint32 size>
using tArray = std::array<type, size>;