#ifndef MOVEMENT_POSITIONTRANSLATION3D_H
#define MOVEMENT_POSITIONTRANSLATION3D_H

#include "space3d.h"

#include "movement-bonefixedpointlist.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-pointlist.h"

namespace Movement
{

	template <typename TVALUE>
	Common::Vector3<TVALUE> getTranslatedPoint(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector3<TVALUE>& position)
	{
		return Space3d::multiplyCoordinateByMatrix(position, boneMap.getBoneTransformMatrix(jointList, parentBoneIndex));
	}

	template <typename TVALUE>
	PointList<Common::Vector3<TVALUE>> getTranslatedJointPoints(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const PointList<Common::Vector3<TVALUE>>& jointPositions)
	{
		PointList<Common::Vector3<TVALUE>> translatedJoints = PointList<Common::Vector3<TVALUE>>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
			translatedJoints.Positions[i]->operator=(getTranslatedPoint(jointList, boneMap, i, *jointPositions.Positions[i]));

		return translatedJoints;
	}
	
	template <typename TVALUE>
	BoneFixedPointList<Common::Vector3<TVALUE>> getTranslatedPoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const BoneFixedPointList<Common::Vector3<TVALUE>>& boneFixedPositions)
	{
		BoneFixedPointList<Common::Vector3<TVALUE>> translatedPoints = BoneFixedPointList<Common::Vector3<TVALUE>>(boneFixedPositions.PositionCount);

		for (UInt8 i = 0; i < boneFixedPositions.PositionCount; i++)
			translatedPoints.Positions[i]->operator=(getTranslatedPoint(jointList, boneMap, boneFixedPositions.BoneIndex[i], *boneFixedPositions.Positions[i]));

		return translatedPoints;
	}

}

#endif // MOVEMENT_POSITIONTRANSLATION3D_H
