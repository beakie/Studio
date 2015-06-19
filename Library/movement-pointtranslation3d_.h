#ifndef MOVEMENT_POINTTRANSLATION3D_H
#define MOVEMENT_POINTTRANSLATION3D_H

#include "space3d.h"

#include "movement-bonefixedpointlist.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-pointlist.h"

namespace Movement
{

	template <typename TVALUE>
	Common::Vector3<TVALUE> getTranslatedPoint(const Common::ICollection<Common::Matrix4<TVALUE>, UInt8>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector3<TVALUE>& position)
	{
		return Space3d::multiplyCoordinateByMatrix(position, boneMap.getBoneTransformMatrix(jointList, parentBoneIndex));
	}

	template <typename TVALUE>
	PointList<Common::Vector3<TVALUE>> getTranslatedJointPositions(const Common::ICollection<Common::Matrix4<TVALUE>, UInt8>& jointList, const BoneMap& boneMap, const Common::ICollection<Common::Vector3<TVALUE>, UInt8>& jointPositions)
	{
		PointList<Common::Vector3<TVALUE>> translatedJoints = PointList<Common::Vector3<TVALUE>>(jointPositions.count());

		for (UInt8 i = 0; i < jointPositions.count(); i++)
			translatedJoints.Points[i]->operator=(getTranslatedPoint(jointList, boneMap, i, *jointPositions.operator[](i)));

		return translatedJoints;
	}
	
	template <typename TVALUE>
	BoneFixedPointList<Common::Vector3<TVALUE>> getTranslatedPoints(const Common::ICollection<Common::Matrix4<TVALUE>, UInt8>& jointList, const BoneMap& boneMap, const BoneFixedPointList<Common::Vector3<TVALUE>>& boneFixedPositions)
	{
		BoneFixedPointList<Common::Vector3<TVALUE>> translatedPoints = BoneFixedPointList<Common::Vector3<TVALUE>>(boneFixedPositions.PointCount);

		for (UInt8 i = 0; i < boneFixedPositions.PointCount; i++)
			translatedPoints.Points[i]->operator=(getTranslatedPoint(jointList, boneMap, boneFixedPositions.BoneIndex[i], *boneFixedPositions.Points[i]));

		return translatedPoints;
	}

	//template <typename TVALUE>
	//Common::Vector3<TVALUE> getTranslatedPoint(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector3<TVALUE>& position)
	//{
	//	return Space3d::multiplyCoordinateByMatrix(position, boneMap.getBoneTransformMatrix(jointList, parentBoneIndex));
	//}

	//template <typename TVALUE>
	//PointList<Common::Vector3<TVALUE>> getTranslatedJointPositions(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const PointList<Common::Vector3<TVALUE>>& jointPositions)
	//{
	//	PointList<Common::Vector3<TVALUE>> translatedJoints = PointList<Common::Vector3<TVALUE>>(jointPositions.PointCount);

	//	for (UInt8 i = 0; i < jointPositions.PointCount; i++)
	//		translatedJoints.Points[i]->operator=(getTranslatedPoint(jointList, boneMap, i, *jointPositions.Points[i]));

	//	return translatedJoints;
	//}

	//template <typename TVALUE>
	//BoneFixedPointList<Common::Vector3<TVALUE>> getTranslatedPoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const BoneFixedPointList<Common::Vector3<TVALUE>>& boneFixedPositions)
	//{
	//	BoneFixedPointList<Common::Vector3<TVALUE>> translatedPoints = BoneFixedPointList<Common::Vector3<TVALUE>>(boneFixedPositions.PointCount);

	//	for (UInt8 i = 0; i < boneFixedPositions.PointCount; i++)
	//		translatedPoints.Points[i]->operator=(getTranslatedPoint(jointList, boneMap, boneFixedPositions.BoneIndex[i], *boneFixedPositions.Points[i]));

	//	return translatedPoints;
	//}

}

#endif // MOVEMENT_POINTTRANSLATION3D_H
