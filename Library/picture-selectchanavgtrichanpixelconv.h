#ifndef PICTURE_SELECTCHANAVGTRICHANPIXELCONV_H
#define PICTURE_SELECTCHANAVGTRICHANPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanAvgTriChanPixelConv
	{
	public:
		TVALUE convertPixel(const Common::Vector3<TVALUE>& pixel)
		{
			return (TVALUE)Common::round(((Common::FloatMax)pixel.Channels[0] + pixel.Channels[1] + pixel.Channels[2]) / 3);
		}
	};
}

#endif // PICTURE_SELECTCHANAVGTRICHANPIXELCONV_H
