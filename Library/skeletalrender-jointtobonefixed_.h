#ifndef SKELETALRENDER_JOINTTOBONEFIXED_H
#define SKELETALRENDER_JOINTTOBONEFIXED_H

#include "movement-bonemap.h"
#include "movement-pointlist.h"
#include "movement-bonefixedpointlist.h"

namespace SkeletalRender
{

	template <typename TPOINT>
	Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> getJointToBoneFixedPositionLines(const Movement::PointList<TPOINT>& jointPointList, const Movement::BoneFixedPointList<TPOINT>& boneFixedPointList)
	{
		Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> lineList = Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8>();

		for (UInt8 i = 0; i < boneFixedPointList.PointCount; i++)
			lineList.add({ *jointPointList.Points[boneFixedPointList.BoneIndex[i]], *boneFixedPointList.Points[i] });

		return lineList;
	}

}

#endif // SKELETALRENDER_JOINTTOBONEFIXED_H
