#ifndef MOVEMENTSKELETALMANIFEST_H
#define MOVEMENTSKELETALMANIFEST_H

#include "movement-skeletal.h"

namespace Movement
{
	template <typename TPOINT, typename TMATRIX>
	struct SkeletalManifest : Skeletal<TPOINT, TMATRIX>
	{

		// Add "MappedPoints" to Skeletal
		//   - BoneIndex, ZeroPositionOffsetX, ZeroPositionOffsetY
		//   - Add constrants?
		//
		// This would mean I would calc the end effector without duplicating each of the joints doing boneFrom/boneTo.

		SkeletalManifest()
		{
		}

		SkeletalManifest(UInt8 chainedBoneCount)
			: Skeletal(chainedBoneCount)
		{
		}
	};
}

#endif // MOVEMENTSKELETALMANIFEST_H
