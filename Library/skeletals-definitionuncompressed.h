#ifndef SKELETALSDEFINITIONUNCOMPRESSED_H
#define SKELETALSDEFINITIONUNCOMPRESSED_H

#include "movement-jointlist.h"

#include "skeletals-definition.h"

namespace Skeletals
{
	template <typename TPOINT, typename TMATRIX>
	struct DefinitionUncompressed : Definition<TPOINT, TMATRIX>
	{
		Movement::JointList<TMATRIX> Joints;
		Movement::JointList<TMATRIX> JointPlacement;

		DefinitionUncompressed()
			: base()
		{
		}

		DefinitionUncompressed(UInt8 chainedBoneCount)
			: base(chainedBoneCount)
		{
		}
	};
}

#endif // SKELETALSDEFINITIONUNCOMPRESSED_H
