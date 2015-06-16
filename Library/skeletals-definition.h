#ifndef SKELETALS_DEFINITION_H
#define SKELETALS_DEFINITION_H

#include "core.h"
#include "common.h"

#include "movement-bonefixedpointlist.h"
#include "movement-bonemap.h"
#include "movement-pointlist.h"
#include "movement-pointtranslation2d_.h"
#include "movement-pointtranslation3d_.h"

namespace Skeletals
{
	template <typename TPOINT, typename TMATRIX>
	struct Definition
	{
		Movement::BoneMap BoneMap;
		Movement::PointList<TPOINT> ZeroPositions;
		Movement::PointList<TPOINT> ZeroRotations;
		Movement::BoneFixedPointList<TPOINT> EndEffectorZeroPositions;

		Definition()
		{
		}

		Definition(UInt8 chainedBoneCount)
			: BoneMap(chainedBoneCount),
			ZeroPositions(chainedBoneCount),
			ZeroRotations(chainedBoneCount)
		{
		}
	};
}

#endif // SKELETALS_DEFINITION_H
