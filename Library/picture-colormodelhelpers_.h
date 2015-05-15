#ifndef PICTURECOLORMODELHELPERS_H
#define PICTURECOLORMODELHELPERS_H

#include "common.h"

namespace Picture
{
	/// <summary>
	/// Returns the red from an RGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbRed(const Common::Vector3<TVALUE>& rgbColor)
	{
		return rgbColor.Channels[0];
	}

	/// <summary>
	/// Returns the blues from an RGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbBlue(const Common::Vector3<TVALUE>& rgbColor)
	{
		return rgbColor.Channels[1];
	}

	/// <summary>
	/// Returns the green from an RGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbGreen(const Common::Vector3<TVALUE>& rgbColor)
	{
		return rgbColor.Channels[2];
	}

	/// <summary>
	/// Returns the hue value an HSV pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getHsvHue(const Common::Vector3<TVALUE>& hsvColor)
	{
		return hsvColor.Channels[0];
	}

	/// <summary>
	/// Returns the saturation from an HSV pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getHsvSaturation(const Common::Vector3<TVALUE>& hsvColor)
	{
		return hsvColor.Channels[1];
	}

	/// <summary>
	/// Returns the value from an HSV pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getHsvValue(const Common::Vector3<TVALUE>& hsvColor)
	{
		return hsvColor.Channels[2];
	}

	/// <summary>
	/// Returns the alpha from an ARGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getArgbAlpha(const Common::Vector4<TVALUE>& argbColor)
	{
		return argbColor.Channels[0];
	}


	/// <summary>
	/// Returns the red from an ARGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getArgbRed(const Common::Vector4<TVALUE>& argbColor)
	{
		return argbColor.Channels[1];
	}

	/// <summary>
	/// Returns the blue from an ARGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getArgbBlue(const Common::Vector4<TVALUE>& argbColor)
	{
		return argbColor.Channels[2];
	}

	/// <summary>
	/// Returns the green from an ARGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getArgbGreen(const Common::Vector4<TVALUE>& argbColor)
	{
		return argbColor.Channels[3];
	}

	/// <summary>
	/// Returns the red from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykCyan(const Common::Vector4<TVALUE>& cmykColor)
	{
		return cmykColor.Channels[0];
	}

	/// <summary>
	/// Returns the blue from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykMagenta(const Common::Vector4<TVALUE>& cmykColor)
	{
		return cmykColor.Channels[1];
	}

	/// <summary>
	/// Returns the green from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykYellow(const Common::Vector4<TVALUE>& cmykColor)
	{
		return cmykColor.Channels[2];
	}

	/// <summary>
	/// Returns the alpha from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykKey(const Common::Vector4<TVALUE>& cmykColor)
	{
		return cmykColor.Channels[3];
	}
}

#endif // PICTURECOLORMODELHELPERS_H
