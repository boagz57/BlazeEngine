#pragma once
#include "Universal/UniversalTypeDefs.h"
#include "Vector3D.h"
#include "Matrix4x4.h"

namespace BlazeFramework
{
	Matrix4x4 Translate(Vector3D amountToMove);
	Matrix4x4 OrthoProjection(sfloat left, sfloat right, sfloat bottom, sfloat top);
	Matrix4x4 Rotate(Vector3D vertsToRotate, sfloat degressToRotate);
}

