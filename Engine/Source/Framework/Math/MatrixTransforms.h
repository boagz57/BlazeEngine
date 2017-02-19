#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Vector3D.h"
#include "Matrix4x4.h"

namespace BlazeFramework
{
	Matrix4x4 Translate(Vector3D amountToMove);
	uint OrthoProjection(sfloat left, sfloat right, sfloat bottom, sfloat top);
}

