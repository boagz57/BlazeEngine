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

//Must switch to false to enable Release build
#define _PROFILE \
	false	

#if (_DEBUG || _PROFILE)
#define LOG(...) \
	do { fprintf(stderr, __VA_ARGS__); } while (0)
#else
#define NDEBUG
#define LOG(...) 
#endif

