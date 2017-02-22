#include "Precompiled.h"
#include "GLM/gtx/transform.hpp"//TODO: For faster implementation, need to use gtc/matrix_transform header
#include "Vector4D.h"
#include "MatrixTransforms.h"

namespace BlazeFramework
{
	Matrix4x4 Translate(Vector3D amountToMove)
	{
		return glm::translate(amountToMove);//TODO: For faster implementation, change this translate function to glm's other translate function which takes in another matrix as a parameter
	}

	Matrix4x4 OrthoProjection(sfloat left, sfloat right, sfloat bottom, sfloat top)
	{
		return glm::ortho(left, right, bottom, top);
	}

	BlazeFramework::Matrix4x4 Rotate(Vector3D vertsToRotate, sfloat degreesToRotate)
	{
		return glm::rotate(degreesToRotate, vertsToRotate);
	}

}

