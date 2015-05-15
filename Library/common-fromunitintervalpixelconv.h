#ifndef COMMONFROMUNITINTERVALPIXELCONV_H
#define COMMONFROMUNITINTERVALPIXELCONV_H

#include "core.h"
#include "common-unitinterval.h"
#include "common-bounds_.h"

namespace Common
{
	template <typename TVALUE, typename TUNITINTERVAL = Common::UnitIntervalMax>
	class FromUnitIntervalPixelConv
	{
	private:
		FloatMax offset;
		FloatMax scale;
	public:

		FromUnitIntervalPixelConv()
		{
			offset = Common::getLowerBound<TVALUE>();
			scale = ((FloatMax)Common::getUpperBound<TVALUE>() - offset);
		}

		TVALUE convertPixel(const TUNITINTERVAL& pixel)
		{
			return (TVALUE)(((FloatMax)pixel * scale) + offset);
		}
	};
}

#endif // COMMONFROMUNITINTERVALPIXELCONV_H
