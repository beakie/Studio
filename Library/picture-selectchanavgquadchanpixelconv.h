#ifndef PICTURESELECTCHANAVGQUADCHANPIXELCONV_H
#define PICTURESELECTCHANAVGQUADCHANPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanAvgQuadChanPixelConv
	{
	public:
		TVALUE convertPixel(const Common::Vector4<TVALUE>& pixel)
		{
			return (TVALUE)Common::round(((Common::FloatMax)pixel.Channels[0] + pixel.Channels[1] + pixel.Channels[2] + pixel.Channels[3]) / 4);
		}
	};
}

#endif // PICTURESELECTCHANAVGQUADCHANPIXELCONV_H
