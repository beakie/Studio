#ifndef SKELETALRENDER_JOINTTOJOINT_H
#define SKELETALRENDER_JOINTTOJOINT_H

#include "movement-bonemap.h"
#include "movement-pointlist.h"

namespace SkeletalRender
{
	template <typename TPOINT>
	Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> getJointToJointBoneLines(const Movement::BoneMap& boneMap, const Movement::PointList<TPOINT>& jointPointList)
	{
		Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> boneList = Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8>();

		for (UInt8 i = 0; i < boneMap.BoneCount; i++)
			if (boneMap.ParentBones[i] != i)
				boneList.add({ *jointPointList.Points[boneMap.ParentBones[i]], *jointPointList.Points[i] });

		return boneList;
	}
}

#endif // SKELETALRENDER_JOINTTOJOINT_H
