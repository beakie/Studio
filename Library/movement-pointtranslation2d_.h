#ifndef MOVEMENT_POINTTRANSLATION2D_H
#define MOVEMENT_POINTTRANSLATION2D_H

#include "space2d.h"

#include "movement-bonefixedpointlist.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-pointlist.h"

namespace Movement
{

	template <typename TVALUE>
	Common::Vector2<TVALUE> getTranslatedPoint(const Movement::JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector2<TVALUE>& position)
	{
		return Space2d::multiplyPlotByMatrix<TVALUE>(position, boneMap.getBoneTransformMatrix<Common::Matrix3<TVALUE>>(jointList, parentBoneIndex));
	}

	template <typename TVALUE>
	PointList<Common::Vector2<TVALUE>> getTranslatedJointPositions(const Movement::JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const PointList<Common::Vector2<TVALUE>>& jointPositions)
	{
		PointList<Common::Vector2<TVALUE>> translatedJoints = PointList<Common::Vector2<TVALUE>>(jointPositions.PointCount);

		for (UInt8 i = 0; i < jointPositions.PointCount; i++)
			translatedJoints.Points[i]->operator=(getTranslatedPoint<TVALUE>(jointList, boneMap, i, *jointPositions.Points[i]));

		return translatedJoints;
	}

	template <typename TVALUE>
	BoneFixedPointList<Common::Vector2<TVALUE>> getTranslatedPoints(const Movement::JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const BoneFixedPointList<Common::Vector2<TVALUE>>& boneFixedPositions)
	{
		BoneFixedPointList<Common::Vector2<TVALUE>> translatedPoints = BoneFixedPointList<Common::Vector2<TVALUE>>(boneFixedPositions.PointCount);

		for (UInt8 i = 0; i < boneFixedPositions.PointCount; i++)
			translatedPoints.Points[i]->operator=(getTranslatedPoint<TVALUE>(jointList, boneMap, boneFixedPositions.BoneIndex[i], *boneFixedPositions.Points[i]));

		return translatedPoints;
	}

}

#endif // MOVEMENT_POINTTRANSLATION2D_H
