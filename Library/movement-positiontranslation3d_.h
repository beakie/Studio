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
	Common::Vector3<TVALUE> getTranslatedPosition(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector3<TVALUE>& position)
	{
		return Space3d::multiplyCoordinateByMatrix(position, boneMap.getBoneTransformMatrix(jointList, parentBoneIndex));
	}

	template <typename TVALUE>
	PositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const PositionList<Common::Vector3<TVALUE>>& jointPositions)
	{
		PositionList<Common::Vector3<TVALUE>> translatedJoints = PositionList<Common::Vector3<TVALUE>>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
			translatedJoints.Positions[i]->operator=(getTranslatedPosition(jointList, boneMap, i, *jointPositions.Positions[i]));

		return translatedJoints;
	}
	
	template <typename TVALUE>
	BoneFixedPositionList<Common::Vector3<TVALUE>> getTranslatedPositions(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const BoneFixedPositionList<Common::Vector3<TVALUE>>& boneFixedPositions)
	{
		BoneFixedPositionList<Common::Vector3<TVALUE>> translatedPositions = BoneFixedPositionList<Common::Vector3<TVALUE>>(boneFixedPositions.PositionCount);

		for (UInt8 i = 0; i < boneFixedPositions.PositionCount; i++)
			translatedPositions.Positions[i]->operator=(getTranslatedPosition(jointList, boneMap, boneFixedPositions.BoneIndex[i], *boneFixedPositions.Positions[i]));

		return translatedPositions;
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION3D_H
