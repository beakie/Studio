#ifndef MOVEMENTSKELETALMANIFEST_H
#define MOVEMENTSKELETALMANIFEST_H

#include "movement-skeletal.h"

namespace Movement
{
	template <typename TPOINT, typename TMATRIX>
	struct SkeletalManifest : Skeletal<TPOINT, TMATRIX>
	{


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
