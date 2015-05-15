#ifndef PICTURERGBTOCMYKPIXELCONV_H
#define PICTURERGBTOCMYKPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	class RgbToCmykPixelConv
	{
		// move function variables to here

	public:
		Common::Vector4<TUNITINTERVAL> convertPixel(const Common::Vector3<TUNITINTERVAL>& pixel)
		{
			FloatMax r = (FloatMax)pixel.Values[0];
			FloatMax g = (FloatMax)pixel.Values[1];
			FloatMax b = (FloatMax)pixel.Values[2];

			if ((r == 0) && (g == 0) && (b == 0))
				return Common::Vector4<TUNITINTERVAL>(0, 0, 0, 1);

			FloatMax c = 1 - r;
			FloatMax m = 1 - g;
			FloatMax y = 1 - b;

			FloatMax minCMY = Common::min(c, m, y);

			return Common::Vector4<TUNITINTERVAL>((c - minCMY) / (1 - minCMY), (m - minCMY) / (1 - minCMY), (y - minCMY) / (1 - minCMY), minCMY);
		}
	};

}

#endif // PICTURERGBTOCMYKPIXELCONV_H

// http://www.javascripter.net/faq/rgb2cmyk.htm
