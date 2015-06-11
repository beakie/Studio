#ifndef SKELETALSDEFINITIONUNCOMPRESSED_H
#define SKELETALSDEFINITIONUNCOMPRESSED_H

#include "skeletals-definition.h"

namespace Skeletals
{
	template <typename TPOINT, typename TMATRIX>
	struct DefinitionUncompressed : Definition<TPOINT, TMATRIX>
	{

		DefinitionUncompressed()
		{
		}

		DefinitionUncompressed(UInt8 chainedBoneCount)
			: base(chainedBoneCount)
		{
		}
	};
}

#endif // SKELETALSDEFINITIONUNCOMPRESSED_H
