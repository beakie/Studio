#ifndef PICTUREHSVTORGBPIXELCONV_H
#define PICTUREHSVTORGBPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	class HsvToRgbPixelConv
	{
		// move function variables to here

	public:
		Common::Vector3<TUNITINTERVAL> convertPixel(const Common::Vector3<TUNITINTERVAL>& pixel)
		{
			FloatMax h = (FloatMax)pixel.Values[0];
			FloatMax s = (FloatMax)pixel.Values[1];
			FloatMax v = (FloatMax)pixel.Values[2];

			if (s == 0)
				return Common::Vector3<TUNITINTERVAL>(v, v, v);

			h = pixel.Values[0] * 6;
			int i = floor(h);
			float f = h - i;
			float p = pixel.Values[2] * (1 - pixel.Values[1]);
			float q = pixel.Values[2] * (1 - pixel.Values[1] * f);
			float t = pixel.Values[2] * (1 - pixel.Values[1] * (1 - f));
			switch (i) {
			case 0:
				return Common::Vector3<TUNITINTERVAL>(v, t, p);
			case 1:
				return Common::Vector3<TUNITINTERVAL>(q, v, p);
			case 2:
				return Common::Vector3<TUNITINTERVAL>(p, v, t);
			case 3:
				return Common::Vector3<TUNITINTERVAL>(p, q, v);
			case 4:
				return Common::Vector3<TUNITINTERVAL>(t, p, v);
			default:
				return Common::Vector3<TUNITINTERVAL>(v, p, q);
			}
		}
	};

}

#endif // PICTUREHSVTORGBPIXELCONV_H
