#ifndef PICTURE_CHAIN2PIXELCONV_H
#define PICTURE_CHAIN2PIXELCONV_H

#include "core.h"
#include "common-ipixelconverter.h"

namespace Common
{
	template <typename TVALUEOUT, typename TCONVERTER1, typename TCONVERTER2, typename TVALUEIN>
	class Chain2PixelConv : IPixelConverter<TVALUEIN, TVALUEOUT>
	{
	private:
		TCONVERTER1* _Converter1;
		TCONVERTER2* _Converter2;

	public:
		Chain2PixelConv(TCONVERTER1* converter1, TCONVERTER2* converter2)
		{
			_Converter1 = converter1;
			_Converter2 = converter2;
		}

		TVALUEOUT convertPixel(const TVALUEIN& pixel)
		{
			return _Converter2->convertPixel(_Converter1->convertPixel(pixel));
		}
	};

}

#endif // PICTURE_CHAIN2PIXELCONV_H
