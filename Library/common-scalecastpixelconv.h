#ifndef COMMON_SCALECASTPIXELCONV_H
#define COMMON_SCALECASTPIXELCONV_H

#include "core.h"
#include "common-ipixelconverter.h"

namespace Common
{
	template <typename TIN, typename TOUT>
	class ScaleCastPixelConv : IPixelConverter<TIN, TOUT>
	{
	private:
		FloatMax offsetIn;
		FloatMax offsetOut;
		FloatMax scale;
	public:

		ScaleCastPixelConv()
		{
			offsetIn = Common::getLowerBound<TIN>();
			offsetOut = Common::getLowerBound<TOUT>();
			scale = (((FloatMax)Common::getUpperBound<TOUT>() - offsetOut) / (Common::getUpperBound<TIN>() - offsetIn));
		}

		TOUT convertPixel(const TIN& pixel)
		{
			return (TOUT)((((FloatMax)pixel - offsetIn) * scale) + offsetOut);
		}
	};
}

#endif // COMMON_SCALECASTPIXELCONV_H
