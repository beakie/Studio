#ifndef SKELETALSDEFINITION_H
#define SKELETALSDEFINITION_H

#include "core.h"
#include "common.h"

#include "movement-bonefixedpositionlist.h"
#include "movement-bonemap.h"
#include "movement-positionlist.h"
#include "movement-positiontranslation2d_.h"
#include "movement-positiontranslation3d_.h"

namespace Skeletals
{
	template <typename TPOINT, typename TMATRIX>
	struct Definition
	{
		Movement::BoneMap BoneMap;
		Movement::PositionList<TPOINT> ZeroPositions;
		Movement::PositionList<TPOINT> ZeroRotation;
		Movement::BoneFixedPositionList<TPOINT> EndEffectorZeroPositions;

		Definition()
		{
		}

		Definition(UInt8 chainedBoneCount)
			: BoneMap(chainedBoneCount),
			ZeroPositions(chainedBoneCount)
		{
		}
	};
}

#endif // SKELETALSDEFINITION_H
