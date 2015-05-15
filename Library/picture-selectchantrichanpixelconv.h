#ifndef PICTURESELECTCHANTRICHANPIXELCONV_H
#define PICTURESELECTCHANTRICHANPIXELCONV_H

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

#endif // PICTURESELECTCHANTRICHANPIXELCONV_H
