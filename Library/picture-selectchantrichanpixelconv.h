#ifndef PICTURE_SELECTCHANTRICHANPIXELCONV_H
#define PICTURE_SELECTCHANTRICHANPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanTriChanPixelConv
	{
	public:
		UInt8 _channel;

		SelectChanTriChanPixelConv(const UInt8 channel)
		{
			_channel = channel;
		}

		TVALUE convertPixel(const Common::Vector3<TVALUE>& pixel)
		{
			return pixel.Values[_channel];
		}
	};
}

#endif // PICTURE_SELECTCHANTRICHANPIXELCONV_H
