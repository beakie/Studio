#ifndef SKELETALRENDERJOINTTOBONEFIXED_H
#define SKELETALRENDERJOINTTOBONEFIXED_H

#include "movement-bonemap.h"
#include "movement-positionlist.h"
#include "movement-bonefixedpositionlist.h"

namespace SkeletalRender
{

	template <typename TVALUE>
	Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8> getJointToBoneFixedPositionLines(Movement::PositionList<Common::Vector2<TVALUE>> jointPositionList, Movement::BoneFixedPositionList<Common::Vector2<TVALUE>> boneFixedPositionList)
	{
		Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8> lineList = Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8>();

		for (UInt8 i = 0; i < boneFixedPositionList.PositionCount; i++)
			lineList.add({ *jointPositionList.Positions[boneFixedPositionList.BoneIndex[i]], *boneFixedPositionList.Positions[i] });

		return lineList;
	}

	template <typename TVALUE>
	Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> getJointToBoneFixedPositionLines(Movement::PositionList<Common::Vector3<TVALUE>> jointPositionList, Movement::BoneFixedPositionList<Common::Vector3<TVALUE>> boneFixedPositionList)
	{
		Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> lineList = Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8>();

		for (UInt8 i = 0; i < boneFixedPositionList.PositionCount; i++)
			lineList.add({ *jointPositionList.Positions[boneFixedPositionList.BoneIndex[i]], *boneFixedPositionList.Positions[i] });

		return lineList;
	}

}

#endif // SKELETALRENDERJOINTTOBONEFIXED_H
