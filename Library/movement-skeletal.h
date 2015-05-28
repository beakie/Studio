#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bonemap.h"
#include "movement-bonefixedpositionlist.h"
#include "movement-positionlist.h"
#include "movement-jointlist.h"

namespace Movement
{
	template <typename TPOINT, typename TMATRIX>
	struct Skeletal
	{
		JointList<TMATRIX> Joints;
		BoneMap BoneMap;
		PositionList<TPOINT> ZeroPositions; // This should be the position of the axis in 3d space. Not the bone ends!
		BoneFixedPositionList<TPOINT> EndEffectors;

		Skeletal()
		{
		}

		Skeletal(UInt8 chainedBoneCount)
			: Joints(chainedBoneCount),
			  BoneMap(chainedBoneCount),
			  ZeroPositions(chainedBoneCount)
		{
		}
	};
}

#endif // MOVEMENTSKELETAL_H
