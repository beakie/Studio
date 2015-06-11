#ifndef PICTURE_SPREADVALUETRICHANPIXELCONV_H
#define PICTURE_SPREADVALUETRICHANPIXELCONV_H

#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SpreadValueTriChanPixelConv
	{
	public:
		Common::Vector3<TVALUE> convertPixel(const TVALUE value)
		{
			return Common::Vector3<TVALUE>(value, value, value);
		}
	};
}

#endif // PICTURE_SPREADVALUETRICHANPIXELCONV_H
