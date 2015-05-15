#ifndef PICTURE_H
#define PICTURE_H

#include "common.h"

#include "picture-argbtorgbpixelconv.h"
#include "picture-cmyktorgbpixelconv.h"
#include "picture-colorhelpers_.h"
#include "picture-colormaps_.h"
#include "picture-colormodelconvbuilders_.h"
#include "picture-colormodelhelpers_.h"
#include "picture-quadchanpixelconvbuilders_.h"
#include "picture-quadcolormap.h"
#include "picture-quadcolormapscaledpixelconv.h"
#include "picture-rgbtoargbpixelconv.h"
#include "picture-rgbtocmykpixelconv.h"
#include "picture-rgbtohsvpixelconv.h"
#include "picture-selectchanavgquadchanpixelconv.h"
#include "picture-selectchanavgtrichanpixelconv.h"
#include "picture-selectchanquadchanpixelconv.h"
#include "picture-selectchantrichanpixelconv.h"
#include "picture-spreadchanquadchanpixelconv.h"
#include "picture-spreadchantrichanpixelconv.h"
#include "picture-spreadvaluequadchanpixelconv.h"
#include "picture-spreadvaluetrichanpixelconv.h"
#include "picture-trichanpixelconvbuilders_.h"
#include "picture-tricolormap.h"
#include "picture-tricolormappalettepixelconv.h"
#include "picture-tricolormapscaledpixelconv.h"

namespace Picture
{
	/// <summary>
	/// 1 byte precision RGB pixel
	/// </summary>
	typedef Common::Vector3<UInt8> Rgb8;
	/// <summary>
	/// 2 byte precision RGB pixel
	/// </summary>
	typedef Common::Vector3<UInt16> Rgb16;
	/// <summary>
	/// 4 byte precision RGB pixel
	/// </summary>
	typedef Common::Vector3<UInt32> Rgb32;
	/// <summary>
	/// 1 byte precision HSV pixel
	/// </summary>
	typedef Common::Vector3<UInt8> Hsv8;
	/// <summary>
	/// 2 byte precision HSV pixel
	/// </summary>
	typedef Common::Vector3<UInt16> Hsv16;
	/// <summary>
	/// 4 byte precision HSV pixel
	/// </summary>
	typedef Common::Vector3<UInt32> Hsv32;
	/// <summary>
	/// 1 byte precision ARGB pixel
	/// </summary>
	typedef Common::Vector4<UInt8> Argb8;
	/// <summary>
	/// 2 byte precision ARGB pixel
	/// </summary>
	typedef Common::Vector4<UInt16> Argb16;
	/// <summary>
	/// 4 byte precision ARGB pixel
	/// </summary>
	typedef Common::Vector4<UInt32> Argb32;
	/// <summary>
	/// 1 byte precision CMYK pixel
	/// </summary>
	typedef Common::Vector4<UInt8> Cmyk8;
	/// <summary>
	/// 2 byte precision CMYK pixel
	/// </summary>
	typedef Common::Vector4<UInt16> Cmyk16;
	/// <summary>
	/// 4 byte precision CMYK pixel
	/// </summary>
	typedef Common::Vector4<UInt32> Cmyk32;
	/// <summary>
	/// 1 byte precision greyscale pixel
	/// </summary>
	typedef UInt8 Grey8;
	/// <summary>
	/// 2 byte precision greyscale pixel
	/// </summary>
	typedef UInt16 Grey16;
	/// <summary>
	/// 4 byte precision greyscale pixel
	/// </summary>
	typedef UInt32 Grey32;

	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<Rgb8, UInt8> Image8Rgb8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<Rgb16, UInt8> Image8Rgb16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<Rgb32, UInt8> Image8Rgb32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<Rgb8, UInt16> Image16Rgb8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<Rgb16, UInt16> Image16Rgb16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<Rgb32, UInt16> Image16Rgb32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<Hsv8, UInt8> Image8Hsv8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<Hsv16, UInt8> Image8Hsv16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<Hsv32, UInt8> Image8Hsv32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<Hsv8, UInt16> Image16Hsv8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<Hsv16, UInt16> Image16Hsv16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<Hsv32, UInt16> Image16Hsv32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision ARGB pixels
	/// </summary>
	typedef Common::Image<Argb8, UInt8> Image8Argb8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision ARGB pixels
	/// </summary>
	typedef Common::Image<Argb16, UInt8> Image8Argb16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision ARGB pixels
	/// </summary>
	typedef Common::Image<Argb32, UInt8> Image8Argb32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision ARGB pixels
	/// </summary>
	typedef Common::Image<Argb8, UInt16> Image16Argb8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision ARGB pixels
	/// </summary>
	typedef Common::Image<Argb16, UInt16> Image16Argb16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision ARGB pixels
	/// </summary>
	typedef Common::Image<Argb32, UInt16> Image16Argb32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<Argb8, UInt8> Image8Cmyk8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<Argb16, UInt8> Image8Cmyk16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<Argb32, UInt8> Image8Cmyk32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<Argb8, UInt16> Image16Cmyk8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<Argb16, UInt16> Image16Cmyk16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<Argb32, UInt16> Image16Cmyk32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte greyscale pixels
	/// </summary>
	typedef Common::Image<Grey8, UInt8> Image8Grey8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte greyscale pixels
	/// </summary>
	typedef Common::Image<Grey16, UInt8> Image8Grey16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte greyscale pixels
	/// </summary>
	typedef Common::Image<Grey32, UInt8> Image8Grey32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte greyscale pixels
	/// </summary>
	typedef Common::Image<Grey8, UInt16> Image16Grey8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte greyscale pixels
	/// </summary>
	typedef Common::Image<Grey16, UInt16> Image16Grey16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte greyscale pixels
	/// </summary>
	typedef Common::Image<Grey32, UInt16> Image16Grey32;

	typedef TriColorMap<Float32> TriColorMap32;

	typedef TriColorMap<Float64> TriColorMap64;

	typedef QuadColorMap<Float32> QuadColorMap32;

	typedef QuadColorMap<Float64> QuadColorMap64;

	//add the rest of these functions. relying entirly on floats sucks.

	typedef TriColorMapScaledPixelConv<Common::UnitInterval32, Float32, UInt8> TriColorMap32PixelConv8;

	typedef TriColorMapScaledPixelConv<Common::UnitInterval32, Float32, UInt16> TriColorMap32PixelConv16;

	typedef TriColorMapScaledPixelConv<Common::UnitInterval32, Float32, UInt32> TriColorMap32PixelConv32;

	typedef TriColorMapScaledPixelConv<Common::UnitInterval64, Float64, UInt8> TriColorMap64PixelConv8;

	typedef TriColorMapScaledPixelConv<Common::UnitInterval64, Float64, UInt16> TriColorMap64PixelConv16;

	typedef TriColorMapScaledPixelConv<Common::UnitInterval64, Float64, UInt32> TriColorMap64PixelConv32;

	typedef QuadColorMapScaledPixelConv<Common::UnitInterval32, Float32, UInt8> QuadColorMap32PixelConv8;

	typedef QuadColorMapScaledPixelConv<Common::UnitInterval32, Float32, UInt16> QuadColorMap32PixelConv16;

	typedef QuadColorMapScaledPixelConv<Common::UnitInterval32, Float32, UInt32> QuadColorMap32PixelConv32;

	typedef QuadColorMapScaledPixelConv<Common::UnitInterval64, Float64, UInt8> QuadColorMap64PixelConv8;

	typedef QuadColorMapScaledPixelConv<Common::UnitInterval64, Float64, UInt16> QuadColorMap64PixelConv16;

	typedef QuadColorMapScaledPixelConv<Common::UnitInterval64, Float64, UInt32> QuadColorMap64PixelConv32;

}

#endif // PICTURE_H
