#pragma once
#include <cstdio>
#include "Boost/BoostAssert.h"
#include <assert.h>

#define DLL  \
	__declspec(dllexport)

#define _PROFILE true

#define RUNTIME_ASSERT BOOST_ASSERT_MSG 
#define COMPILETIME_ASSERT(expr, msg) static_assert(expr, msg) 

#if (_DEBUG || _PROFILE)
#define LOG(...) \
	do { fprintf(stderr, __VA_ARGS__); } while (0)
#else
#define LOG(...) 
#define NDEBUG
#endif

