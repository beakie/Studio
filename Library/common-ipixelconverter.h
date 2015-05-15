#ifndef COMMONIPIXELCONVERTER_H
#define COMMONIPIXELCONVERTER_H

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

#endif // COMMONIPIXELCONVERTER_H
