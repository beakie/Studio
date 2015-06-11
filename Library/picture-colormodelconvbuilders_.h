#ifndef PICTURE_COLORMODELCONVBUILDERS_H
#define PICTURE_COLORMODELCONVBUILDERS_H

#include "common.h"
#include "picture-hsvtorgbpixelconv.h"
#include "picture-rgbtohsvpixelconv.h"
#include "picture-spreadchantrichanpixelconv.h"
#include "picture-selectchantrichanpixelconv.h"
#include "picture-selectchanavgtrichanpixelconv.h"

namespace Picture
{

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadRedRgbPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadGreenRgbPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadBlueRgbPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectRedRgbPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectGreenRgbPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectBlueRgbPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanAvgTriChanPixelConv<TVALUE> getRgbIntensityPixelConv()
	{
		return SelectChanAvgTriChanPixelConv<TVALUE>();
	}

	template <typename TVALUE>
	RgbToHsvPixelConv<TVALUE> getRgbToHsvPixelConv()
	{
		return RgbToHsvPixelConv<TVALUE>();
	}

	template <typename TVALUE>
	HsvToRgbPixelConv<TVALUE> getHsvToRgbPixelConv()
	{
		return HsvToRgbPixelConv<TVALUE>();
	}

}

#endif // PICTURE_COLORMODELCONVBUILDERS_H
