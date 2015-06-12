#ifndef PICTURE_CHAIN3PIXELCONV_H
#define PICTURE_CHAIN3PIXELCONV_H

#include "core.h"
#include "common-ipixelconverter.h"

namespace Common
{
	template <typename TVALUEOUT, typename TCONVERTER1, typename TCONVERTER2, typename TCONVERTER3, typename TVALUEIN>
	class Chain3PixelConv : IPixelConverter<TVALUEIN, TVALUEOUT>
	{
	private:
		TCONVERTER1* _Converter1;
		TCONVERTER2* _Converter2;
		TCONVERTER3* _Converter3;

	public:
		Chain3PixelConv(TCONVERTER1* converter1, TCONVERTER2* converter2, TCONVERTER3* converter3)
		{
			_Converter1 = converter1;
			_Converter2 = converter2;
			_Converter3 = converter3;
		}

		TVALUEOUT convertPixel(const TVALUEIN& pixel)
		{
			return _Converter3->convertPixel(_Converter2->convertPixel(_Converter1->convertPixel(pixel)));
		}
	};

}

#endif // PICTURE_CHAIN3PIXELCONV_H
