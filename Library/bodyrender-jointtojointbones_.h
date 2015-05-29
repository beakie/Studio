#ifndef BODYRENDERRENDERBONES_H
#define BODYRENDERRENDERBONES_H

#include "skeletals.h"

namespace BodyRender
{
	template <typename TVALUE>
	Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8> getJointToJointBones(Movement::PositionList<Common::Vector2<TVALUE>> positionList, Movement::BoneMap boneMap)
	{
		Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8> boneList = Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8>();

		for (UInt8 i = 0; i < boneMap.BoneCount; i++)
			if (boneMap.ParentBones[i] == i)
				boneList.add({ Common::Vector2<TVALUE>::getZero(), *positionList.Positions[i] });
			else
				boneList.add({ *positionList.Positions[boneMap.ParentBones[i]], *positionList.Positions[i] });

		return boneList;
	}

	template <typename TVALUE>
	Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> getJointToJointBones(Movement::PositionList<Common::Vector3<TVALUE>> positionList, Movement::BoneMap boneMap)
	{
		Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> boneList = Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8>();

		for (UInt8 i = 0; i < boneMap.BoneCount; i++)
			if (boneMap.ParentBones[i] == i)
				boneList.add({ Common::Vector3<TVALUE>::getZero(), *positionList.Positions[i] });
			else
				boneList.add({ *positionList.Positions[boneMap.ParentBones[i]] , * positionList.Positions[i] });

		return boneList;
	}
}

#endif // BODYRENDERRENDERBONES_H
