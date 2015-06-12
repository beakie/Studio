#ifndef PICTURE_SPREADVALUEQUADCHANPIXELCONV_H
#define PICTURE_SPREADVALUEQUADCHANPIXELCONV_H

#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SpreadValueQuadChanPixelConv : Common::IPixelConverter<TVALUE, Common::Vector4<TVALUE>>
	{
	public:
		Common::Vector4<TVALUE> convertPixel(const TVALUE value)
		{
			return Common::Vector4<TVALUE>(value, value, value, value);
		}
	};
}

#endif // PICTURE_SPREADVALUEQUADCHANPIXELCONV_H
