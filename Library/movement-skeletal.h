#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positionlist.h"
#include "movement-jointlist.h"

namespace Movement
{
	template <typename TPOINT, typename TMATRIX>
	struct Skeletal
	{
		JointList<TMATRIX> Joints; // This works for basic translations/rotations, but what about skew and similar? Points along bone could require bespoke matrix? Is this right?
		BoneMap BoneMap;
		PositionList<TPOINT> ZeroPositions; // This should be the position of the axis in 3d space. Not the bone ends!
		// There could be a representation of the bones but zero positions shouldnt be it. it only have a use when rendering the skeletal. Do i need skeletalrender?


		Skeletal()
		{
		}

		Skeletal(UInt8 chainedBoneCount)
			: Joints(chainedBoneCount),
			  BoneMap(chainedBoneCount),
			  ZeroPositions(chainedBoneCount)
			  // this represents the bones (ends). why not the bone starts. what about non linear?
		{
		}
	};
}

#endif // MOVEMENTSKELETAL_H
