#ifndef MOVEMENTPOSITIONTRANSLATION3D_H
#define MOVEMENTPOSITIONTRANSLATION3D_H

#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	template <typename TVALUE>
	PositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const PositionList<Common::Vector3<TVALUE>>& jointPositions)
	{
		PositionList<Common::Vector3<TVALUE>> translatedJoints = PositionList<Common::Vector3<TVALUE>>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
			translatedJoints.Positions[i]->operator=(Space3d::multiplyCoordinateByMatrix(*jointPositions.Positions[i], boneMap.getBoneTransformMatrix(jointList, i)));

		return translatedJoints;
	}
	
	template <typename TVALUE>
	PositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>& skeletal)
	{
		return getTranslatedJoints<TVALUE>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION3D_H
