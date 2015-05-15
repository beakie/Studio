#ifndef PICTURECHAIN3PIXELCONV_H
#define PICTURECHAIN3PIXELCONV_H

#include "core.h"

namespace Common
{
	template <typename TVALUEOUT, typename TCONVERTER1, typename TCONVERTER2, typename TVALUEIN>
	class Chain2PixelConv
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

	template <typename TVALUEOUT, typename TCONVERTER1, typename TCONVERTER2, typename TCONVERTER3, typename TVALUEIN>
	class Chain3PixelConv
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

	template <typename TVALUEOUT, typename TCONVERTER1, typename TCONVERTER2, typename TCONVERTER3, typename TCONVERTER4, typename TVALUEIN>
	class Chain4PixelConv
	{
	private:
		TCONVERTER1* _Converter1;
		TCONVERTER2* _Converter2;
		TCONVERTER3* _Converter3;
		TCONVERTER4* _Converter4;

	public:
		Chain4PixelConv(TCONVERTER1* converter1, TCONVERTER2* converter2, TCONVERTER3* converter3, TCONVERTER4* converter4)
		{
			_Converter1 = converter1;
			_Converter2 = converter2;
			_Converter3 = converter3;
			_Converter4 = converter4;
		}

		TVALUEOUT convertPixel(const TVALUEIN& pixel)
		{
			return _Converter4->convertPixel(_Converter3->convertPixel(_Converter2->convertPixel(_Converter1->convertPixel(pixel))));
		}
	};

}

#endif // PICTURECHAIN3PIXELCONV_H
