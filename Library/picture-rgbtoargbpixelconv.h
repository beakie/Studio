#ifndef PICTURE_RGBTOARGBPIXELCONV_H
#define PICTURE_RGBTOARGBPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class RgbToArgbPixelConv
	{
		// move function variables to here

	public:
		Common::Vector4<TVALUE> convertPixel(const Common::Vector3<TVALUE>& pixel)
		{
			return Common::Vector4<TVALUE>(1, pixel.Values[0], pixel.Values[1], pixel.Values[2]);
		}
	};

}

#endif // PICTURE_RGBTOARGBPIXELCONV_H
