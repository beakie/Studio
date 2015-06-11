#ifndef COMMON_IPIXELCONVERTER_H
#define COMMON_IPIXELCONVERTER_H

#include "core.h"

namespace Common
{
	template <typename TVALUEIN, typename TVALUEOUT>
	class IPixelConverter
	{
		virtual TVALUEOUT convertPixel(const TVALUEIN& pixel) = 0;

		virtual ~IPixelConverter()
		{
		}
	};
}

#endif // COMMON_IPIXELCONVERTER_H
