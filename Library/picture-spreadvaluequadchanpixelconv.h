#ifndef PICTURESPREADVALUEQUADCHANPIXELCONV_H
#define PICTURESPREADVALUEQUADCHANPIXELCONV_H

#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SpreadValueQuadChanPixelConv
	{
	public:
		Common::Vector4<TVALUE> convertPixel(const TVALUE value)
		{
			return Common::Vector4<TVALUE>(value, value, value, value);
		}
	};
}

#endif // PICTURESPREADVALUEQUADCHANPIXELCONV_H
