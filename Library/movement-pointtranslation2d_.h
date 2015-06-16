#ifndef MOVEMENT_POSITIONTRANSLATION2D_H
#define MOVEMENT_POSITIONTRANSLATION2D_H

#include "space2d.h"

#include "movement-bonefixedpointlist.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-pointlist.h"

namespace Movement
{

	template <typename TVALUE>
	Common::Vector2<TVALUE> getTranslatedPoint(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector2<TVALUE>& position)
	{
		return Space2d::multiplyPlotByMatrix(position, boneMap.getBoneTransformMatrix(jointList, parentBoneIndex));
	}

	template <typename TVALUE>
	PointList<Common::Vector2<TVALUE>> getTranslatedJointPoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const PointList<Common::Vector2<TVALUE>>& jointPositions)
	{
		PointList<Common::Vector2<TVALUE>> translatedJoints = PointList<Common::Vector2<TVALUE>>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
			translatedJoints.Positions[i]->operator=(getTranslatedPoint(jointList, boneMap, i, *jointPositions.Positions[i]));

		return translatedJoints;
	}

	template <typename TVALUE>
	BoneFixedPointList<Common::Vector2<TVALUE>> getTranslatedPoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const BoneFixedPointList<Common::Vector2<TVALUE>>& boneFixedPositions)
	{
		BoneFixedPointList<Common::Vector2<TVALUE>> translatedPoints = BoneFixedPointList<Common::Vector2<TVALUE>>(boneFixedPositions.PositionCount);

		for (UInt8 i = 0; i < boneFixedPositions.PositionCount; i++)
			translatedPoints.Positions[i]->operator=(getTranslatedPoint(jointList, boneMap, boneFixedPositions.BoneIndex[i], *boneFixedPositions.Positions[i]));

		return translatedPoints;
	}

}

#endif // MOVEMENT_POSITIONTRANSLATION2D_H
