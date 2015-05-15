#ifndef PICTURESELECTCHANQUADCHANPIXELCONV_H
#define PICTURESELECTCHANQUADCHANPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanQuadChanPixelConv
	{
	public:
		UInt8 _channel;

		SelectChanQuadChanPixelConv(const UInt8 channel)
		{
			_channel = channel;
		}

		TVALUE convertPixel(const Common::Vector4<TVALUE>& pixel)
		{
			return pixel.Values[_channel];
		}
	};
}

#endif // PICTURESELECTCHANQUADCHANPIXELCONV_H
