#ifndef COMMONSCALECASTPIXELCONV_H
#define COMMONSCALECASTPIXELCONV_H

#include "core.h"

namespace Common
{
	template <typename TIN, typename TOUT>
	class ScaleCastPixelConv
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

#endif // COMMONSCALECASTPIXELCONV_H
