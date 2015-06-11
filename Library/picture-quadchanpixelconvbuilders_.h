#ifndef PICTURE_QUADCHANPIXELCONVBUILDERS_H
#define PICTURE_QUADCHANPIXELCONVBUILDERS_H

#include "picture-spreadchanquadchanpixelconv.h"
#include "picture-selectchanquadchanpixelconv.h"

namespace Picture
{
	template <typename TVALUE>
	SpreadChanQuadChanPixelConv<TVALUE> getSpread0QuadChanPixelConv()
	{
		return SpreadChanQuadChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SpreadChanQuadChanPixelConv<TVALUE> getSpread1QuadChanPixelConv()
	{
		return SpreadChanQuadChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SpreadChanQuadChanPixelConv<TVALUE> getSpread2QuadChanPixelConv()
	{
		return SpreadChanQuadChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SpreadChanQuadChanPixelConv<TVALUE> getSpread3QuadChanPixelConv()
	{
		return SpreadChanQuadChanPixelConv<TVALUE>(3);
	}

	template <typename TVALUE>
	SelectChanQuadChanPixelConv<TVALUE> getSelect0QuadChanPixelConv()
	{
		return SelectChanQuadChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SelectChanQuadChanPixelConv<TVALUE> getSelect1QuadChanPixelConv()
	{
		return SelectChanQuadChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SelectChanQuadChanPixelConv<TVALUE> getSelect2QuadChanPixelConv()
	{
		return SelectChanQuadChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanQuadChanPixelConv<TVALUE> getSelect3QuadChanPixelConv()
	{
		return SelectChanQuadChanPixelConv<TVALUE>(3);
	}

}

#endif // PICTURE_QUADCHANPIXELCONVBUILDERS_H
