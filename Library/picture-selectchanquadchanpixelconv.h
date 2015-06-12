#ifndef PICTURE_SELECTCHANQUADCHANPIXELCONV_H
#define PICTURE_SELECTCHANQUADCHANPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanQuadChanPixelConv : Common::IPixelConverter<Common::Vector4<TVALUE>, TVALUE>
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

#endif // PICTURE_SELECTCHANQUADCHANPIXELCONV_H
