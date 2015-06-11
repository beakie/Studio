#ifndef PICTURE_CMYKTORGBPIXELCONV_H
#define PICTURE_CMYKTORGBPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	class CmykToRgbPixelConv
	{
		// move function variables to here

	public:
		Common::Vector3<TUNITINTERVAL> convertPixel(const Common::Vector4<TUNITINTERVAL>& pixel)
		{
			TUNITINTERVAL k = 1 - ((TUNITINTERVAL)pixel.Values[3]);

			return Common::Vector3<TUNITINTERVAL>((1 - ((TUNITINTERVAL)pixel.Values[0])) * k, (1 - ((TUNITINTERVAL)pixel.Values[1])) * k, (1 - ((TUNITINTERVAL)pixel.Values[2])) * k);
		}
	};

}

#endif // PICTURE_CMYKTORGBPIXELCONV_H
