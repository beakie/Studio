#ifndef COMMON_TOUNITINTERVALPIXELCONV_H
#define COMMON_TOUNITINTERVALPIXELCONV_H

#include "core.h"
#include "common-unitinterval.h"
#include "common-bounds_.h"

namespace Common
{
	template <typename TVALUE, typename TUNITINTERVAL = Common::UnitIntervalMax>
	class ToUnitIntervalPixelConv
	{
	private:
		FloatMax offset;
		FloatMax scale;
	public:

		ToUnitIntervalPixelConv()
		{
			offset = Common::getLowerBound<TVALUE>();
			scale = ((FloatMax)Common::getUpperBound<TVALUE>() - offset);
		}

		TUNITINTERVAL convertPixel(const TVALUE& pixel)
		{
			return (TUNITINTERVAL)(((FloatMax)pixel - offset) / scale);
		}
	};
}

#endif // COMMON_TOUNITINTERVALPIXELCONV_H
