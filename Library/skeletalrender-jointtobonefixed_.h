#ifndef SKELETALRENDER_JOINTTOBONEFIXED_H
#define SKELETALRENDER_JOINTTOBONEFIXED_H

#include "movement-bonemap.h"
#include "movement-positionlist.h"
#include "movement-bonefixedpositionlist.h"

namespace SkeletalRender
{

	template <typename TPOINT>
	Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> getJointToBoneFixedPositionLines(const Movement::PositionList<TPOINT>& jointPositionList, const Movement::BoneFixedPositionList<TPOINT>& boneFixedPositionList)
	{
		Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> lineList = Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8>();

		for (UInt8 i = 0; i < boneFixedPositionList.PositionCount; i++)
			lineList.add({ *jointPositionList.Positions[boneFixedPositionList.BoneIndex[i]], *boneFixedPositionList.Positions[i] });

		return lineList;
	}

}

#endif // SKELETALRENDER_JOINTTOBONEFIXED_H
