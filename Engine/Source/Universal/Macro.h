#pragma once
#include <cstdio>
#include "Boost/BoostAssert.h"
#include <assert.h>

#define DLL  \
	__declspec(dllexport)

#define RUNTIME_ASSERT \
	BOOST_ASSERT_MSG 

#define COMPILETIME_ASSERT(expr, msg) \
	static_assert(expr, msg) 

#if (_DEBUG)
#define LOG(...) \
	do { fprintf(stderr, __VA_ARGS__); } while (0)

#elif (_PROFILE)
#define LOG(...)

#else
#define NDEBUG
#define LOG(...) 
#endif

