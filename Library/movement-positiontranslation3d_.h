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
	Common::Vector3<TVALUE> getTranslatedPoint(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector3<TVALUE>& point)
	{
		return Space3d::multiplyCoordinateByMatrix(point, boneMap.getBoneTransformMatrix(jointList, parentBoneIndex));
	}

	template <typename TVALUE>
	PointList<Common::Vector3<TVALUE>> getTranslatedJointPoints(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const PointList<Common::Vector3<TVALUE>>& jointPoints)
	{
		PointList<Common::Vector3<TVALUE>> translatedJoints = PointList<Common::Vector3<TVALUE>>(jointPoints.PointCount);

		for (UInt8 i = 0; i < jointPoints.PointCount; i++)
			translatedJoints.Points[i]->operator=(getTranslatedPoint(jointList, boneMap, i, *jointPoints.Points[i]));

		return translatedJoints;
	}
	
	template <typename TVALUE>
	BoneFixedPointList<Common::Vector3<TVALUE>> getTranslatedPoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const BoneFixedPointList<Common::Vector3<TVALUE>>& boneFixedPoints)
	{
		BoneFixedPointList<Common::Vector3<TVALUE>> translatedPoints = BoneFixedPointList<Common::Vector3<TVALUE>>(boneFixedPoints.PointCount);

		for (UInt8 i = 0; i < boneFixedPoints.PointCount; i++)
			translatedPoints.Points[i]->operator=(getTranslatedPoint(jointList, boneMap, boneFixedPoints.BoneIndex[i], *boneFixedPoints.Points[i]));

		return translatedPoints;
	}

}

#endif // MOVEMENT_POSITIONTRANSLATION3D_H
