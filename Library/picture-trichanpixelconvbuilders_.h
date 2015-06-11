#ifndef PICTURE_TRICHANPIXELCONVBUILDERSCONV_H
#define PICTURE_TRICHANPIXELCONVBUILDERSCONV_H

#include "common.h"
#include "picture-spreadchantrichanpixelconv.h"
#include "picture-selectchantrichanpixelconv.h"

namespace Picture
{
	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getSpread0TriChanPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getSpread1TriChanPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getSpread2TriChanPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelect0TriChanPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelect1TriChanPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelect2TriChanPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(2);
	}

}

#endif // PICTURE_TRICHANPIXELCONVBUILDERSCONV_H
