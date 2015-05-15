#ifndef PICTURERGBTOHSVPIXELCONV_H
#define PICTURERGBTOHSVPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	class RgbToHsvPixelConv
	{
		// move function variables to here

	public:
		Common::Vector3<TUNITINTERVAL> convertPixel(const Common::Vector3<TUNITINTERVAL>& pixel)
		{
			FloatMax r = (FloatMax)pixel.Values[0];
			FloatMax g = (FloatMax)pixel.Values[1];
			FloatMax b = (FloatMax)pixel.Values[2];

			FloatMax max = Common::max(r, g, b);
			FloatMax min = Common::min(r, g, b);
			FloatMax delta = max - min;

			FloatMax h, s, v;

			v = max;

			if (max != 0)
				s = delta / max;		// s
			else {
				s = 0;
				h = -1;
				return Common::Vector3<TUNITINTERVAL>(h, s, v);
			}
			if (r == max)
				h = (g - b) / delta;		// between yellow & magenta
			else if (g == max)
				h = 2 + (b - r) / delta;	// between cyan & yellow
			else
				h = 4 + (r - g) / delta;	// between magenta & cyan
			h *= 60;				// degrees
			if (h < 0)
				h += 360;
			
			return Common::Vector3<TUNITINTERVAL>(h / 360, s, v);
		}
	};

}

#endif // PICTURERGBTOHSVPIXELCONV_H

// http://www.cs.rit.edu/~ncs/color/t_convert.html
