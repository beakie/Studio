#ifndef SKELETALRENDERJOINTTOJOINT_H
#define SKELETALRENDERJOINTTOJOINT_H

#include "movement-bonemap.h"
#include "movement-positionlist.h"

namespace SkeletalRender
{
	template <typename TPOINT>
	Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> getJointToJointBoneLines(Movement::BoneMap boneMap, Movement::PositionList<TPOINT> jointPositionList)
	{
		Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> boneList = Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8>();

		for (UInt8 i = 0; i < boneMap.BoneCount - 1; i++)
			if (boneMap.ParentBones[i] != i)
				boneList.add({ *jointPositionList.Positions[boneMap.ParentBones[i]], *jointPositionList.Positions[i] });

		return boneList;
	}
}

#endif // SKELETALRENDERJOINTTOJOINT_H
