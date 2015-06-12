#ifndef PICTURE_SELECTCHANAVGQUADCHANPIXELCONV_H
#define PICTURE_SELECTCHANAVGQUADCHANPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanAvgQuadChanPixelConv : Common::IPixelConverter<Common::Vector4<TVALUE>, TVALUE>
	{
	public:
		TVALUE convertPixel(const Common::Vector4<TVALUE>& pixel)
		{
			return (TVALUE)Common::round(((Common::FloatMax)pixel.Channels[0] + pixel.Channels[1] + pixel.Channels[2] + pixel.Channels[3]) / 4);
		}
	};
}

#endif // PICTURE_SELECTCHANAVGQUADCHANPIXELCONV_H
