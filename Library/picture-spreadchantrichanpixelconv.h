#ifndef PICTURESPREADCHANTRICHANPIXELCONV_H
#define PICTURESPREADCHANTRICHANPIXELCONV_H

#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SpreadChanTriChanPixelConv
	{
	public:
		UInt8 _channel;

		SpreadChanTriChanPixelConv(const UInt8 channel)
		{
			_channel = channel;
		}

		Common::Vector3<TVALUE> convertPixel(const Common::Vector3<TVALUE>& pixel)
		{
			TVALUE value = pixel.Channels[_channel];
			return Common::Vector3<TVALUE>(value, value, value);
		}
	};
}

#endif // PICTURESPREADCHANTRICHANPIXELCONV_H
